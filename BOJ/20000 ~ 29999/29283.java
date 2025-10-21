import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        int k = new Scanner(System.in).nextInt();
        long addTime = 30;
        long time = 0;
        for (int i = 1; i <= k; i++) {
            time += addTime;
            if (i % 5 == 0) {
                addTime += 30;
            }
        }
        System.out.println(time);
    }
}