import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int S = Integer.parseInt(st.nextToken());
        int speed = 0;
        for (int i = 0; i < N; i++) {
            int a = Integer.parseInt(br.readLine());
            speed += a;
            if (i < N - 1 && speed > S) {
                speed--;
            }
        }
        System.out.println(speed);
    }
}