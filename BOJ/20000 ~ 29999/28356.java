import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Scanner;

public class Main {

    static final int[] nx = {-1, -1, 0, 1, 1, 1, 0, -1}, ny = {0, 1, 1, 1, 0, -1, -1, -1};

    static int getPositionTestNum(int[][] tests, int x, int y) {
        boolean[] testNum = new boolean[5];
        for (int i = 0; i < 8; i++) {
            int nextx = x + nx[i];
            int nexty = y + ny[i];
            if (nextx < 0 || nextx >= tests.length || nexty < 0 || nexty >= tests[0].length) {
                continue;
            }
            testNum[tests[nextx][nexty]] = true;
        }
        for (int i = 1; i <= 4; i++) {
            if (!testNum[i]) {
                return i;
            }
        }
        return -1;
    }

    public static void main(String[] args) throws IOException {

        Scanner sc = new Scanner(System.in);
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int N = sc.nextInt();
        int M = sc.nextInt();
        int K = 1;
        int[][] tests = new int[N][M];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                tests[i][j] = getPositionTestNum(tests, i, j);
                K = Math.max(K, tests[i][j]);
            }
        }
        bw.write(K + "\n");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                bw.write(tests[i][j] + " ");
            }
            bw.write("\n");
        }
        bw.flush();
        bw.close();
    }
}