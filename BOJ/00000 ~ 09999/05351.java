import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        while (n-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int[] coins = new int[st.countTokens()];
            int[] dp = new int[st.countTokens()];
            for (int i = 0; st.hasMoreTokens(); i++) {
                coins[i] = Integer.parseInt(st.nextToken());
            }
            dp[0] = coins[0];
            dp[1] = Math.max(dp[0], coins[1]);
            for (int i = 2; i < coins.length; i++) {
                dp[i] = Math.max(dp[i - 1], dp[i - 2] + coins[i]);
            }
            bw.write(dp[dp.length - 1] + "\n");
        }
        br.close();
        bw.flush();
        bw.close();
    }
}