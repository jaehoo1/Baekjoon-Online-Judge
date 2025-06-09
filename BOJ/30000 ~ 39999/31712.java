import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int CU = sc.nextInt();
        int DU = sc.nextInt();
        int CD = sc.nextInt();
        int DD = sc.nextInt();
        int CP = sc.nextInt();
        int DP = sc.nextInt();
        int H = sc.nextInt();
        for (int time = 0; ; time++) {
            if (time % CU == 0) {
                H -= DU;
            }
            if (time % CD == 0) {
                H -= DD;
            }
            if (time % CP == 0) {
                H -= DP;
            }
            if (H <= 0) {
                System.out.println(time);
                break;
            }
        }
    }
}