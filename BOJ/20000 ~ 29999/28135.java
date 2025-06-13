import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int cnt = 1;
        for (int i = 1; i < N; i++, cnt++) {
            if (String.valueOf(i).contains("50")) {
                cnt++;
            }
        }
        System.out.println(cnt);
    }
}