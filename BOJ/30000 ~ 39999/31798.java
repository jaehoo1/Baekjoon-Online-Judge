import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();

        if (a == 0) {
            System.out.println(c * c - b);
        } else if (b == 0) {
            System.out.println(c * c - a);
        } else if (c == 0) {
            System.out.println((int) Math.sqrt(a + b));
        }
    }
}