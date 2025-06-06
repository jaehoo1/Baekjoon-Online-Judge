import java.util.Scanner;

public class Main {

    static boolean isSpecialYear(int year) {

        String s = String.valueOf(year);
        return year == Math.pow(Integer.parseInt(s.substring(0, 2)) + Integer.parseInt(s.substring(2)), 2);
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int X = sc.nextInt();
        while (++X < 10000) {
            if (isSpecialYear(X)) {
                System.out.println(X);
                System.exit(0);
            }
        }
        System.out.println(-1);
    }
}