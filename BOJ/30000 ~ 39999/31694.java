import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int[] algosia = new int[11];
        int[] bajtek = new int[11];
        int asum = 0, bsum = 0;
        for (int i = 0; i < 18; i++) {
            int score = sc.nextInt();
            algosia[score]++;
            asum += score;
        }
        for (int i = 0; i < 18; i++) {
            int score = sc.nextInt();
            bajtek[score]++;
            bsum += score;
        }
        if (asum > bsum) {
            System.out.println("Algosia");
            System.exit(0);
        } else if (asum < bsum) {
            System.out.println("Bajtek");
            System.exit(0);
        } else {
            for (int i = 10; i > 0; i--) {
                if (algosia[i] > bajtek[i]) {
                    System.out.println("Algosia");
                    System.exit(0);
                } else if (algosia[i] < bajtek[i]) {
                    System.out.println("Bajtek");
                    System.exit(0);
                }
            }
        }
        System.out.println("remis");
    }
}