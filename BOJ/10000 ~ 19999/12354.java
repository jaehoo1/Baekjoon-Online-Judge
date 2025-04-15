import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int T, N;
        T = sc.nextInt();
        for (int t = 1; t <= T; t++) {
            N = sc.nextInt();
            int cur, pre, cnt = 1;
            pre = sc.nextInt();
            for (int i = 1; i < N; i++) {
                cur = sc.nextInt();
                if (cur > pre) {
                    cnt++;
                }
                pre = cur;
            }
            System.out.println("Case #" + t + ": " + (N - cnt));
        }
    }
}