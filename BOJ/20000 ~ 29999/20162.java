import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int[] snacks = new int[N];
        int[] dp = new int[N];

        for (int i = 0; i < N; i++) {
            snacks[i] = Integer.parseInt(br.readLine());
        }
        for (int i = 0; i < N; i++) {
            int preMax = 0;
            for (int j = 0; j < i; j++) {
                if (snacks[i] > snacks[j]) {
                    preMax = Math.max(preMax, dp[j]);
                }
            }
            dp[i] = preMax + snacks[i];
        }
        System.out.println(Arrays.stream(dp).max().getAsInt());
    }
}