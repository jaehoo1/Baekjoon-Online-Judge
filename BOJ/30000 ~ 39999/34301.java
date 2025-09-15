import java.util.Arrays;
import java.util.Scanner;

public class Main {

    static final int[] UNITS = {1, 5, 15, 30, 150};

    public static void main(String[] args) {

        int[] bills = new int[5];
        int N = new Scanner(System.in).nextInt();
        for (int i = 4; i >= 0 && N > 0; i--) {
            bills[i] = N / UNITS[i];
            N %= UNITS[i];
        }
        Arrays.stream(bills)
                .forEach(bill -> System.out.print(bill + " "));
    }
}