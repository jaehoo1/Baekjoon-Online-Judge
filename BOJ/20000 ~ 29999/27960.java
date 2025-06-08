import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        boolean[] A = new boolean[10];
        boolean[] B = new boolean[10];
        boolean[] C = new boolean[10];
        int SA = sc.nextInt();
        int SB = sc.nextInt();
        for (int i = 9, sum = 0; i >= 0; i--) {
            if (sum + Math.pow(2, i) <= SA) {
                sum += Math.pow(2, i);
                A[i] = true;
            }
            if (sum >= SA) {
                break;
            }
        }
        for (int i = 9, sum = 0; i >= 0; i--) {
            if (sum + Math.pow(2, i) <= SB) {
                sum += Math.pow(2, i);
                B[i] = true;
            }
            if (sum >= SB) {
                break;
            }
        }
        int SC = 0;
        for (int i = 0; i < 10; i++) {
            if ((A[i] && !B[i]) || (!A[i] && B[i])) {
                SC += Math.pow(2, i);
            }
        }
        System.out.println(SC);
    }
}