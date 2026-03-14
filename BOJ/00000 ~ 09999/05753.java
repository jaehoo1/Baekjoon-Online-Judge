import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int D = Integer.parseInt(st.nextToken());
            if (N == 0 && D == 0) {
                break;
            }
            int[][] attendees = new int[D][N];
            for (int i = 0; i < D; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < N; j++) {
                    attendees[i][j] = Integer.parseInt(st.nextToken());
                }
            }
            boolean isAttendedAll = false;
            for (int j = 0; j < N; j++) {
                for (int i = 0; i < D; i++) {
                    if (attendees[i][j] == 0) {
                        break;
                    }
                    if (i == D - 1) {
                        isAttendedAll = true;
                    }
                }
            }
            bw.write(isAttendedAll ? "yes\n" : "no\n");
        }
        br.close();
        bw.flush();
        bw.close();
    }
}