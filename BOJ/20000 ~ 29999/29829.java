import java.util.Arrays;
import java.util.Scanner;

public class Main {

    static int[] arr = new int[4];

    static boolean isPalindrome() {
        return arr[0] == arr[3] && arr[1] == arr[2];
    }

    static boolean canPalindrome() {
        return arr[0] == arr[3] || arr[1] == arr[2];
    }

    static void changePalindrome() {
        if (arr[0] == arr[3]) {
            arr[2] = arr[1];
        } else {
            arr[3] = arr[0];
        }
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        for (int i = 0; i < 4; i++) {
            arr[i] = sc.nextInt();
        }
        if (isPalindrome() || canPalindrome()) {
            changePalindrome();
            System.out.println("JAH");
            Arrays.stream(arr).forEach(i -> System.out.print(i + " "));
        } else {
            System.out.println("EI");
        }
    }
}