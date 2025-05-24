import java.io.*;
import java.util.ArrayList;
import java.util.List;

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

    static List<Integer> kmp(String text, String pattern) {

        int[] pi = getPi(pattern);
        int j = 0;
        List<Integer> results = new ArrayList<>();

        for (int i = 0; i < text.length(); i++) {
            while (j > 0 && text.charAt(i) != pattern.charAt(j)) {
                j = pi[j - 1];
            }

            if (text.charAt(i) == pattern.charAt(j)) {
                j++;
                if (j == pattern.length()) {
                    results.add(i - pattern.length() + 1);
                    j = pi[j - 1];
                }
            }
        }
        return results;
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        List<Integer> kmp = kmp(br.readLine(), br.readLine());
        bw.write(kmp.size() + "\n");
        for (int i : kmp) {
            bw.write(i + 1 + " ");
        }
        br.close();
        bw.flush();
        bw.close();
    }
}