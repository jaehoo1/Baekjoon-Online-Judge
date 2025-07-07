import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int P = Integer.parseInt(br.readLine());
        while (P-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            bw.write(st.nextToken() + " ");
            int M = Integer.parseInt(st.nextToken());
            long pre = 1;
            long cur = 1;
            int period = 2;
            while (true) {
                long next = (pre + cur) % M;
                pre = cur;
                cur = next;
                period++;
                if (pre == 0 && cur == 1) {
                    break;
                }
            }
            bw.write(period - 1 + "\n");
        }
        br.close();
        bw.flush();
        bw.close();
    }
}