import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static void invalid() {
        System.out.println(-1);
        System.exit(0);
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        long[][] blocks = new long[N][N];
        int Mx = -1, My = -1;
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                blocks[i][j] = Integer.parseInt(st.nextToken());
                if (blocks[i][j] == 0) {
                    Mx = i;
                    My = j;
                }
            }
        }
        long rsum = 0;
        for (int i = 0; i < N; i++) {
            rsum += blocks[Mx - 1 < 0 ? Mx + 1 : Mx - 1][i];
        }
        blocks[Mx][My] = rsum - Arrays.stream(blocks[Mx]).sum();
        for (int i = 0; i < N; i++) {
            if (rsum != Arrays.stream(blocks[i]).sum()) {
                invalid();
            }
        }
        for (int i = 0; i < N; i++) {
            long csum = 0;
            for (int j = 0; j < N; j++) {
                csum += blocks[j][i];
            }
            if (rsum != csum) {
                invalid();
            }
        }
        long dsum1 = 0, dsum2 = 0;
        for (int i = 0; i < N; i++) {
            dsum1 += blocks[i][i];
            dsum2 += blocks[i][N - i - 1];
        }
        if (rsum != dsum1 || rsum != dsum2) {
            invalid();
        }
        System.out.println(blocks[Mx][My] < 0 ? -1 : blocks[Mx][My]);
    }
}