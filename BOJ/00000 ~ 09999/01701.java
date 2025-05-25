import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

    static int[] getPi(String pattern) {

        int[] pi = new int[pattern.length()];
        int j = 0;

        for (int i = 1; i < pattern.length(); i++) {
            while (j > 0 && pattern.charAt(i) != pattern.charAt(j)) {
                j = pi[j - 1];
            }

            if (pattern.charAt(i) == pattern.charAt(j)) {
                j++;
                pi[i] = j;
            }
        }
        return pi;
    }

    public static void main(String[] args) throws IOException {

        int max = 0;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        for (int i = 0; i < s.length(); i++) {
            max = Math.max(max, Arrays.stream(getPi(s.substring(i)))
                    .max()
                    .getAsInt());
        }
        System.out.println(max);
    }
}