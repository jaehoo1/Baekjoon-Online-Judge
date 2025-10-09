import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        int count = 0;
        int N = new Scanner(System.in).nextInt();
        while (N != 1) {
            if (N % 2 == 0) {
                N /= 2;
            } else {
                N += N * 2 + 1;
            }
            count++;
        }
        System.out.println(count);
    }
}