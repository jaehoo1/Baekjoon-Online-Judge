import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        StringTokenizer st = new StringTokenizer(new BufferedReader(new InputStreamReader(System.in)).readLine());
        String[] cenas = new String[3];
        for (int i = 0; i < 3; i++) {
            cenas[i] = st.nextToken();
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < cenas[i].length(); j++) {
                if (i > 0 && j == 0 && cenas[i - 1].charAt(cenas[i - 1].length() - 1) == cenas[i].charAt(0)) {
                    System.out.print('\'');
                } else {
                    System.out.print(cenas[i].charAt(j));
                }
            }
        }
    }
}