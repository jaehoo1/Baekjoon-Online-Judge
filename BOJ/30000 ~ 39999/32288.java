import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();
        String s = scanner.nextLine();

        for (int i = 0; i < n; i++) {
            char c = s.charAt(i);
            if (c <= 'Z') {
                System.out.print(String.valueOf(c).toLowerCase());
            } else {
                System.out.print(String.valueOf(c).toUpperCase());
            }
        }
    }
}
