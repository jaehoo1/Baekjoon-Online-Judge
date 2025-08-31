import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {

        String s = new BufferedReader(new InputStreamReader(System.in)).readLine();
        int cou = 0;
        for (int i = 0; i < s.length(); i++) {
            if (i >= s.length() - 3) {
                break;
            }
            if (s.charAt(i) == 'k' && s.charAt(i + 1) == 'i' && s.charAt(i + 2) == 'c' && s.charAt(i + 3) == 'k') {
                cou++;
            }
        }
        System.out.println(cou);
    }
}