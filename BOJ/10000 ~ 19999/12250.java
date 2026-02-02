import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());
        for (int t = 1; t <= T; t++) {
            int cnt = 0;
            StringTokenizer st = new StringTokenizer(br.readLine());
            int A = Integer.parseInt(st.nextToken());
            int B = Integer.parseInt(st.nextToken());
            int K = Integer.parseInt(st.nextToken());
            for (int i = 0; i < A; i++) {
                for (int j = 0; j < B; j++) {
                    if ((i & j) < K) {
                        cnt++;
                    }
                }
            }
            bw.write("Case #" + t + ": " + cnt + "\n");
        }
        br.close();
        bw.flush();
        bw.close();
    }
}