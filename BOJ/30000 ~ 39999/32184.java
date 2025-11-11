import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int A = sc.nextInt();
        int B = sc.nextInt();
        int picture = 0;
        while (A <= B) {
            picture++;
            A += A % 2 == 0 ? 1 : 2;
        }
        System.out.println(picture);
    }
}