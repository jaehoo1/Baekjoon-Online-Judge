import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int X = sc.nextInt();
        int Y = sc.nextInt();
        int Z = sc.nextInt();
        int U = sc.nextInt();
        int V = sc.nextInt();
        int W = sc.nextInt();
        System.out.println(U / 100 * X + V / 50 * Y + W / 20 * Z);
    }
}