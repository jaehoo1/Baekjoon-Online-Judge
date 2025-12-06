import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            int n = Integer.parseInt(br.readLine());
            int[] v = new int[n];
            int[] u = new int[n];
            int hamming = 0;
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; i++) {
                v[i] = Integer.parseInt(st.nextToken());
            }
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; i++) {
                u[i] = Integer.parseInt(st.nextToken());
            }
            for (int i = 0; i < n; i++) {
                if (v[i] != u[i]) {
                    hamming++;
                }
            }
            bw.write(hamming + "\n");
        }
        br.close();
        bw.flush();
        bw.close();
    }
}