import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            if (n == 0 && m == 0) {
                break;
            }
            boolean[] found = new boolean[n + 1];
            found[m] = true;
            for (int i = 0; i < n - 2; i++) {
                found[Integer.parseInt(br.readLine())] = true;
            }
            for (int i = 1; i <= n; i++) {
                if (!found[i]) {
                    bw.write(i + "\n");
                }
            }
        }
        br.close();
        bw.flush();
        bw.close();
    }
}