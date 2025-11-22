import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        boolean min = false, max = false;
        for (int i = 0; i < n - 1; i++) {
            int w = Integer.parseInt(br.readLine());
            if (w == a) {
                min = true;
            }
            if (w == b) {
                max = true;
            }
        }
        if (!min && !max) {
            System.out.println(-1);
        } else if (!min) {
            System.out.println(a);
        } else if (!max) {
            System.out.println(b);
        } else {
            for (int i = a; i <= b; i++) {
                System.out.println(i);
            }
        }
    }
}