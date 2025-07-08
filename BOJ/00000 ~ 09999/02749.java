import java.util.Scanner;

public class Main {

    static final int PISANO_PERIOD = 1500000;

    public static void main(String[] args) {

        long[] fibo = new long[PISANO_PERIOD];
        fibo[0] = 0;
        fibo[1] = 1;
        for (int i = 2; i < PISANO_PERIOD; i++) {
            fibo[i] = (fibo[i - 2] + fibo[i - 1]) % 1000000;
        }

        Scanner sc = new Scanner(System.in);
        System.out.println(fibo[(int) (sc.nextLong() % PISANO_PERIOD)]);
    }
}