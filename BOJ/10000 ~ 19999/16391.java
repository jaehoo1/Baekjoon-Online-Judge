import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < N; i++) {
            sb.append(br.readLine());
        }
        String s = sb.toString();
        long result = 0;
        for (int i = 0; i < N; i++) {
            if (s.charAt(N - i - 1) == 'O') {
                result |= (1L << i);
            }
        }
        System.out.println(result);
    }
}