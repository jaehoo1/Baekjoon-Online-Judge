import java.util.Scanner;

public class Main {

    static int N, M;
    static int[] dp;

    static int skillCombination(int time) {
        if (time <= 0) {
            return 0;
        }
        if (time == 1) {
            return 1;
        }
        if (time == M) {
            return 2;
        }
        if (dp[time] > 0) {
            return dp[time];
        }
        return dp[time] = (skillCombination(time - 1) + skillCombination(time - M)) % 1000000007;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        dp = new int[N + 1];
        System.out.println(skillCombination(N));
    }
}