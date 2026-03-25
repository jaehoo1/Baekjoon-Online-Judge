import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());
        for (int t = 1; t <= T; t++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int R = Integer.parseInt(st.nextToken());
            int C = Integer.parseInt(st.nextToken());
            char[][] cells = new char[2 * R + 1][2 * C + 1];
            for (int i = 0; i < 2 * R + 1; i++) {
                Arrays.fill(cells[i], '.');
            }
            for (int i = 0; i < 2 * R + 1; i += 2) {
                for (int j = 0; j < 2 * C + 1; j += 2) {
                    cells[i][j] = '+';
                }
            }
            for (int i = 0; i < 2 * R + 1; i += 2) {
                for (int j = 1; j < 2 * C + 1; j += 2) {
                    cells[i][j] = '-';
                }
            }
            for (int i = 1; i < 2 * R + 1; i += 2) {
                for (int j = 0; j < 2 * C + 1; j += 2) {
                    cells[i][j] = '|';
                }
            }
            cells[0][0] = cells[0][1] = cells[1][0] = cells[1][1];

            bw.write("Case #" + t + ":\n");
            for (int i = 0; i < 2 * R + 1; i++) {
                for (int j = 0; j < 2 * C + 1; j++) {
                    bw.write(cells[i][j]);
                }
                bw.write("\n");
            }
        }
        br.close();
        bw.flush();
        bw.close();
    }
}