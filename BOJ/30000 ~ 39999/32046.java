import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        while (true) {
            int n = Integer.parseInt(br.readLine());
            if (n == 0) {
                break;
            }
            int sum = 0;
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; i++) {
                int a = Integer.parseInt(st.nextToken());
                if (sum + a <= 300) {
                    sum += a;
                }
            }
            bw.write(sum + "\n");
        }
        br.close();
        bw.flush();
        bw.close();
    }
}