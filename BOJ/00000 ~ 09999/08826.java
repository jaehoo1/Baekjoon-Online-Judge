import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int Z = Integer.parseInt(br.readLine());
        while (Z-- > 0) {
            int n = Integer.parseInt(br.readLine());
            String directions = br.readLine();
            int N = 0, S = 0, W = 0, E = 0;
            for (int i = 0; i < n; i++) {
                char c = directions.charAt(i);
                if (c == 'N') {
                    N++;
                } else if (c == 'S') {
                    S++;
                } else if (c == 'W') {
                    W++;
                } else if (c == 'E') {
                    E++;
                }
            }
            System.out.println(Math.abs(N - S) + Math.abs(W - E));
        }
    }
}