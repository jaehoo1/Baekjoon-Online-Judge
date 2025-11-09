import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        char[][] xRay = new char[N][M];
        for (int i = 0; i < N; i++) {
            xRay[i] = br.readLine().toCharArray();
        }
        for (int i = 0; i < N - 1; i++) {
            for (int j = 0; j < M - 1; j++) {
                if (xRay[i][j] == '1' && xRay[i][j + 1] == '1' && xRay[i + 1][j] == '1' && xRay[i + 1][j + 1] == '1') {
                    System.out.println(1);
                    System.exit(0);
                }
            }
        }
        System.out.println(0);
    }
}