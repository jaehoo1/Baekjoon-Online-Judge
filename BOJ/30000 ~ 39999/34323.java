import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        long N = sc.nextInt();
        long M = sc.nextInt();
        long S = sc.nextInt();
        double a, b;
        a = (double) S * (M + 1) / 100 * (100 - N);
        b = (double) S * M;
        System.out.println(a < b ? (long) a : (long) b);
    }
}