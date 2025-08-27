import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        String[] split = new Scanner(System.in).nextLine().split("/");
        int a = Integer.parseInt(split[0]);
        int b = Integer.parseInt(split[1]);
        if (a > 12) {
            System.out.println("EU");
        } else if (b > 12) {
            System.out.println("US");
        } else {
            System.out.println("either");
        }
    }
}