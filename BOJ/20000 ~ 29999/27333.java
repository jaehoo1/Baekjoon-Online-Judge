import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.stream.IntStream;

public class Main {

    static String[] TWO_LOWERCASE, TWO_UPPERCASE;

    static boolean isTwoLowercaseAdjacent(String s) {

        for (int i = 0; i < 26; i++) {
            if (s.contains(TWO_LOWERCASE[i])) {
                return true;
            }
        }
        return false;
    }

    static String twoUppercase(String s) {
        for (int i = 0; i < 26; i++) {
            s = s.replace(TWO_LOWERCASE[i], TWO_UPPERCASE[i]);
        }
        return s;
    }

    public static void main(String[] args) throws IOException {

        TWO_LOWERCASE = IntStream.range(0, 26)
                .mapToObj(i -> "" + (char) ('a' + i) + (char) ('a' + i))
                .toArray(String[]::new);
        TWO_UPPERCASE = IntStream.range(0, 26)
                .mapToObj(i -> "" + (char) ('A' + i) + (char) ('A' + i))
                .toArray(String[]::new);

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        String S = br.readLine();
        while (isTwoLowercaseAdjacent(S)) {
            S = twoUppercase(S);
        }
        System.out.println(S);
    }
}