import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int P = sc.nextInt();
        int M = sc.nextInt();
        int C = sc.nextInt();
        int X = sc.nextInt();
        int min = Integer.MAX_VALUE;
        for (int p = 1; p <= P; p++) {
            for (int m = 1; m <= M; m++) {
                for (int c = 1; c <= C; c++) {
                    min = Math.min(
                            Math.abs((p + m) * (m + c) - X),
                            min
                    );
                }
            }
        }
        System.out.println(min);
    }
}