import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int h = Integer.parseInt(st.nextToken());
        int w = Integer.parseInt(st.nextToken());
        int[][] tiles = new int[h][w];
        int[][] dp = new int[h][w];
        for (int i = 0; i < h; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < w; j++) {
                tiles[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        for (int i = 0; i < w; i++) {
            dp[0][i] = tiles[0][i];
        }
        for (int i = 1; i < h; i++) {
            for (int j = 0; j < w; j++) {
                for (int k = -1; k <= 1; k++) {
                    if (j + k < 0 || j + k >= w) {
                        continue;
                    }
                    dp[i][j] = Math.max(dp[i][j], dp[i - 1][j + k]);
                }
                dp[i][j] += tiles[i][j];
            }
        }
        System.out.println(Arrays.stream(dp[h - 1]).max().getAsInt());
    }
}