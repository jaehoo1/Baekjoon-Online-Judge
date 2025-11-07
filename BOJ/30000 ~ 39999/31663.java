import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] sums = new int[45];
        int[] lengths = new int[45];
        int N = Integer.parseInt(br.readLine());
        for (int i = 0; i < N; i++) {
            String word = br.readLine();
            for (int j = 0; j < word.length(); j++) {
                sums[j] += word.charAt(j);
                lengths[j]++;
            }
        }
        for (int i = 0; i < 45 && lengths[i] > 0; i++) {
            System.out.print((char) Math.floor((double) sums[i] / lengths[i]));
        }
    }
}