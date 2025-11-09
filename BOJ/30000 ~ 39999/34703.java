import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        boolean[] lectures = new boolean[6];
        int N = Integer.parseInt(br.readLine());
        for (int i = 0; i < N; i++) {
            lectures[Integer.parseInt(br.readLine())] = true;
        }
        for (int i = 1; i < 6; i++) {
            if (!lectures[i]) {
                System.out.println("YES");
                System.exit(0);
            }
        }
        System.out.println("NO");
    }
}