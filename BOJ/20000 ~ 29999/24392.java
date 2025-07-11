import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        boolean[][] board = new boolean[N][M];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                board[i][j] = st.nextToken().equals("1");
            }
        }
        int[][] dp = new int[N][M];
        int[] ny = {-1, 0, 1};
        for (int i = 0; i < M; i++) {
            dp[N - 1][i] = board[N - 1][i] ? 1 : 0;
        }
        for (int i = N - 1; i > 0; i--) {
            for (int j = 0; j < M; j++) {
                if (!board[i][j]) {
                    continue;
                }
                for (int k = 0; k < 3; k++) {
                    int nexty = j + ny[k];
                    if (nexty < 0 || nexty >= M || !board[i - 1][nexty]) {
                        continue;
                    }
                    dp[i - 1][nexty] += dp[i][j];
                    dp[i - 1][nexty] %= 1000000007;
                }
            }
        }
        int result = 0;
        for (int i = 0; i < M; i++) {
            result += dp[0][i];
            result %= 1000000007;
        }
        System.out.println(result);
    }
}