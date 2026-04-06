import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int X = Integer.parseInt(st.nextToken());
            int Y = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(br.readLine());
            int[] colors = new int[N];
            for (int i = 0; i < N; i++) {
                colors[i] = Integer.parseInt(st.nextToken());
            }
            boolean easy = colors[0] == X;
            boolean hard = colors[N - 1] == Y;
            if (easy && hard) {
                bw.write("BOTH\n");
            } else if (easy) {
                bw.write("EASY\n");
            } else if (hard) {
                bw.write("HARD\n");
            } else {
                bw.write("OKAY\n");
            }
        }
        br.close();
        bw.flush();
        bw.close();
    }
}