import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int O = 0;
        String S = br.readLine();
        for (int i = 0; i < N; i++) {
            if (S.charAt(i) == 'O') {
                O++;
            }
        }
        System.out.println(O >= (double) N / 2 ? "Yes" : "No");
    }
}