import java.io.*;
import java.util.StringTokenizer;

public class Main {

    static int diff(int elapsedTime) {
        return Math.abs(2023 - elapsedTime);
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        while (true) {
            int n = Integer.parseInt(br.readLine());
            if (n == 0) {
                break;
            }
            int minDiff = Integer.MAX_VALUE;
            int winner = 0;
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; i++) {
                int elapsedTime = Integer.parseInt(st.nextToken());
                int diff = diff(elapsedTime);
                if (diff < minDiff) {
                    minDiff = diff;
                    winner = i + 1;
                }
            }
            bw.write(winner + "\n");
        }
        br.close();
        bw.flush();
        bw.close();
    }
}
