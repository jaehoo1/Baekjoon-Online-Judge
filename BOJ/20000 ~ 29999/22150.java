import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int[] l = new int[n];
            int[] r = new int[n];
            for (int i = 0; i < 2 * n; i++) {
                if (i % 2 == 0) {
                    l[i / 2] = Integer.parseInt(st.nextToken());
                } else {
                    r[i / 2] = Integer.parseInt(st.nextToken());
                }
            }
            boolean eaten = false;
            for (int i = 0; i < n; i++) {
                if (l[i] + r[i] != n) {
                    eaten = true;
                    break;
                }
            }
            bw.write(eaten ? "yes\n" : "no\n");
        }
        br.close();
        bw.flush();
        bw.close();
    }
}