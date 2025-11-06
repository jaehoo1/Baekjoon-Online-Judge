import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int s = sc.nextInt();
        int c = sc.nextInt();
        c += sc.nextInt() * 2;
        s += sc.nextInt();
        System.out.println(Math.min(s / 3, c / 6));
    }
}