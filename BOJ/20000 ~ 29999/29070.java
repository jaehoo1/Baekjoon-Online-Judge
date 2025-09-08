import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int h = sc.nextInt();
        int w = sc.nextInt();
        System.out.println((h / a + (h % a == 0 ? 0 : 1)) * (w / b + (w % b == 0 ? 0 : 1)));
    }
}