import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        int N = new Scanner(System.in).nextInt();
        int cnt = 0;
        for (int i = 0; 4 * i <= N; i++) {
            if ((N - 4 * i) % 5 == 0) {
                cnt++;
            }
        }
        System.out.println(cnt);
    }
}