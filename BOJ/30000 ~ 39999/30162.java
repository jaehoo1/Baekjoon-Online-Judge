import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        int n = new Scanner(System.in).nextInt();
        System.out.println(n % 2 == 0 ? (int) Math.pow(2, n / 2) : 0);
    }
}