import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        for (int seq = 1; ; seq++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            if (n == 0 && m == 0 && c == 0) {
                break;
            }

            int[] amperes = new int[n + 1];
            boolean[] onOff = new boolean[n + 1];
            int sum = 0, max = 0;
            boolean blown = false;
            for (int i = 1; i <= n; i++) {
                amperes[i] = Integer.parseInt(br.readLine());
            }
            for (int i = 0; i < m; i++) {
                int num = Integer.parseInt(br.readLine());
                onOff[num] = !onOff[num];
                sum += onOff[num] ? amperes[num] : -amperes[num];
                if (sum > c) {
                    blown = true;
                }
                if (sum > max) {
                    max = sum;
                }
            }
            bw.write("Sequence " + seq + "\n");
            if (blown) {
                bw.write("Fuse was blown.\n");
            } else {
                bw.write("Fuse was not blown.\n");
                bw.write("Maximal power consumption was " + max + " amperes.\n");
            }
            bw.write("\n");
        }
        br.close();
        bw.flush();
        bw.close();
    }
}