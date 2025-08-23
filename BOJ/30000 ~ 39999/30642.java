import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        String mascot = sc.next();
        int K = sc.nextInt();
        int toilet = 0;
        if (mascot.equals("annyong")) {
            if (K % 2 == 1) {
                toilet = K;
            } else {
                toilet = K + 1 <= N ? K + 1 : K - 1;
            }
        } else if (mascot.equals("induck")) {
            if (K % 2 == 0) {
                toilet = K;
            } else {
                toilet = K + 1 <= N ? K + 1 : K - 1;
            }
        }
        System.out.println(toilet);
    }
}