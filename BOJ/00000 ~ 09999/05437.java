import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while(T-- > 0) {
            int P = sc.nextInt();
            int N = sc.nextInt();
            int sum = 0;
            Integer[] arr = new Integer[N];
            for (int i = 0; i < N; i++) {
                arr[i] = sc.nextInt();
            }
            Arrays.sort(arr, Collections.reverseOrder());
            for (int i = 0; i < N / (P + 1); i++) {
                sum += arr[i];
            }
            System.out.println(sum);
        }
    }
}