import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), pre, cur, max = 1, cnt = 1;
        sc.nextInt();
        pre = sc.nextInt();
        for (int i = 1; i < n; i++) {
            cur = sc.nextInt();
            if (pre == cur) {
                max = Math.max(max, cnt);
                cnt = 1;
            } else {
                cnt++;
            }
            pre = cur;
        }
        System.out.println(Math.max(max, cnt));
    }
}