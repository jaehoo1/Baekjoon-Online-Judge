import java.util.Scanner;

public class Main {

    static boolean isPrime(long num) {

        for (long i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {

        int N = new Scanner(System.in).nextInt();
        for (int i = N; i <= 1000000000; i++) {
            if (!isPrime(i)) {
                System.out.println(i);
                System.exit(0);
            }
        }
        for (int i = N - 1; i > 1; i--) {
            if (!isPrime(i)) {
                System.out.println(i);
                break;
            }
        }
    }
}