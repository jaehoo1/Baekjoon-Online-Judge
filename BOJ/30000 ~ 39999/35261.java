import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    static final String EAGLE = "eagle";

    static int matches(String s, int index) {
        if (index + 5 > s.length()) {
            return 0;
        }
        int cnt = 0;
        for (int i = 0; i < 5; i++) {
            if (s.charAt(i + index) == EAGLE.charAt(i)) {
                cnt++;
            }
        }
        return cnt;
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        String s = br.readLine();
        int max = 0;
        for (int i = 0; i < N; i++) {
            max = Math.max(max, matches(s, i));
        }
        System.out.println(5 - max);
    }
}