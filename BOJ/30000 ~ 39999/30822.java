import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    final static String UOSPC = "uospc";

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        br.readLine();
        int[] countChar = new int[26];
        for (char c : br.readLine().toCharArray()) {
            countChar[c - 'a']++;
        }
        int min = Integer.MAX_VALUE;
        for (char c : UOSPC.toCharArray()) {
            min = Math.min(min, countChar[c - 'a']);
        }
        System.out.println(min);
    }
}