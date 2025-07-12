import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static String max(String a, String b) {

        if (a == null) {
            return b;
        }
        if (b == null) {
            return a;
        }
        int i;
        for (i = 0; i < a.length() && a.charAt(i) == b.charAt(i); i++);
        if (i == a.length() || a.charAt(i) == '1') {
            return a;
        }
        return b;
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[][] arr = new int[N][N];
        int[] nx = {0, 1}, ny = {1, 0};
        String[][] dp = new String[N][N];
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        dp[0][0] = String.valueOf(arr[0][0]);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < 2; k++) {
                    int nextx = i + nx[k];
                    int nexty = j + ny[k];
                    if (nextx >= N || nexty >= N) {
                        continue;
                    }
                    String next = dp[i][j] + arr[nextx][nexty];
                    dp[nextx][nexty] = max(dp[nextx][nexty], next);
                }
            }
        }
        System.out.println(Long.parseLong(dp[N - 1][N - 1], 2));
    }
}