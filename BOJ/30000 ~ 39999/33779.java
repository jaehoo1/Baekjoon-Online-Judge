import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    static boolean isPalindrome(String s) {
        for (int i = 0; i < s.length() / 2; i++) {
            if (s.charAt(i) != s.charAt(s.length() - i - 1)) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) throws IOException {

        System.out.println(isPalindrome(new BufferedReader(new InputStreamReader(System.in)).readLine()) ? "beep" : "boop");
    }
}