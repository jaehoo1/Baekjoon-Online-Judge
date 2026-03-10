import java.util.Scanner;

public class Main {

    static boolean containsEvenPalindrome(String s) {

        for (int i = 0; i < s.length() - 1; i++) {
            if (s.charAt(i) == s.charAt(i + 1)) {
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) {

        System.out.println(containsEvenPalindrome(new Scanner(System.in).nextLine()) ? "Or not." : "Odd.");
    }
}