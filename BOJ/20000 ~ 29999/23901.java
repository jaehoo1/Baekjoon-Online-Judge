import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int T = Integer.parseInt(br.readLine());
        for (int t = 1; t <= T; t++) {
            int N = Integer.parseInt(br.readLine());
            int[] H = new int[N];
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 0; i < N; i++) {
                H[i] = Integer.parseInt(st.nextToken());
            }
            int peak = 0;
            for (int i = 1; i < N - 1; i++) {
                if (H[i] > H[i - 1] && H[i] > H[i + 1]) {
                    peak++;
                }
            }
            bw.write("Case #" + t + ": " + peak + "\n");
        }
        br.close();
        bw.flush();
        bw.close();
    }
}