import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String s = br.readLine();
        int N = 0, S = 0, W = 0, E = 0;
        for (int i = 0; i < n; i++) {
            char c = s.charAt(i);
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
        System.out.println(n - Math.max(Math.max(Math.max(N, S), W), E));
    }
}