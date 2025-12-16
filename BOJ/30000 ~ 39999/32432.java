import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();
        int i;
        for (i = 1; N * i + N - 1 <= K; i++);
        System.out.println(i - 1);
    }
}