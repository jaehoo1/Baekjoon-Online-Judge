import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int[] counts = new int[51];
        int n = Integer.parseInt(br.readLine());
        boolean output = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 10; j++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                for (int k = 0; k < 5; k++) {
                    counts[Integer.parseInt(st.nextToken())]++;
                }
            }
        }
        for (int i = 1; i <= 50; i++) {
            if (counts[i] > 2 * n) {
                bw.write(i + " ");
                output = true;
            }
        }
        if (!output) {
            bw.write("-1");
        }
        bw.write("\n");
        br.close();
        bw.flush();
        bw.close();
    }
}