import java.io.*;
import java.util.StringTokenizer;

public class Main {

    static boolean[][] monster;
    static int R, C;

    static boolean isSafe(int x, int y, int l) {
        for (int i = x; i < x + l; i++) {
            if (i >= R) {
                return false;
            }
            for (int j = y; j < y + l; j++) {
                if (j >= C) {
                    return false;
                }
                if (monster[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int T = Integer.parseInt(br.readLine());
        for (int t = 1; t <= T; t++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            R = Integer.parseInt(st.nextToken());
            C = Integer.parseInt(st.nextToken());
            int K = Integer.parseInt(st.nextToken());
            monster = new boolean[R][C];
            while (K-- > 0) {
                st = new StringTokenizer(br.readLine());
                monster[Integer.parseInt(st.nextToken())][Integer.parseInt(st.nextToken())] = true;
            }
            int safeZones = 0;
            for (int l = 1; l <= Math.min(R, C); l++) {
                for (int i = 0; i < R; i++) {
                    for (int j = 0; j < C; j++) {
                        if (isSafe(i, j, l)) {
                            safeZones++;
                        }
                    }
                }
            }
            bw.write("Case #" + t + ": " + safeZones + "\n");
        }
        br.close();
        bw.flush();
        bw.close();
    }
}