import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int drO = sc.nextInt();
        int alyssa = sc.nextInt();
        int konari = sc.nextInt();
        for (int a = 1; a * alyssa < drO; a++) {
            for (int k = 1; a * alyssa + k * konari <= drO; k++) {
                if (a * alyssa + k * konari == drO) {
                    System.out.println(1);
                    System.exit(0);
                }
            }
        }
        System.out.println(0);
    }
}