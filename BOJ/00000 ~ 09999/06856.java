import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt();
        int n = sc.nextInt();
        int ways = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (i + j == 10) {
                    ways++;
                }
            }
        }
        if (ways == 1) {
            System.out.println("There is 1 way to get the sum 10.");
        } else {
            System.out.println("There are " + ways + " ways to get the sum 10.");
        }
    }
}