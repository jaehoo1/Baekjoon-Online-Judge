import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {

        String encrypted = new BufferedReader(new InputStreamReader(System.in)).readLine();
        String decrypted = "";
        for (int i = 0; i < encrypted.length(); i++) {
            for (int j = i + 1; j <= encrypted.length(); j++) {
                String substring = encrypted.substring(i, j);
                if (decrypted.compareTo(substring) < 0) {
                    decrypted = substring;
                }
            }
        }
        System.out.println(decrypted);
    }
}