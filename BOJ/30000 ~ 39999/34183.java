import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        int A = sc.nextInt();
        int B = sc.nextInt();
        System.out.println(M >= N * 3 ? 0 : (N * 3 - M) * A + B);
    }
}