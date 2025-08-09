import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int B = Integer.parseInt(st.nextToken());
            int N = Integer.parseInt(st.nextToken());
            if (B == 0 && N == 0) {
                break;
            }
            double min = Integer.MAX_VALUE;
            int i = 0, A = 0;
            for (i = 0; Math.pow(i, N) <= B; i++) {
                double diff = Math.abs(Math.pow(i, N) - B);
                if (min > diff) {
                    min = diff;
                    A = i;
                }
            }
            double diff = Math.abs(Math.pow(i, N) - B);
            if (min > diff) {
                A = i;
            }
            bw.write(A + "\n");
        }
        br.close();
        bw.flush();
        bw.close();
    }
}