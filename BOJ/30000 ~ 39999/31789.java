import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int X = Integer.parseInt(st.nextToken());
        int S = Integer.parseInt(st.nextToken());
        while (N-- > 0) {
            st = new StringTokenizer(br.readLine());
            int c = Integer.parseInt(st.nextToken());
            int p = Integer.parseInt(st.nextToken());
            if (c <= X && p > S) {
                System.out.println("YES");
                System.exit(0);
            }
        }
        System.out.println("NO");
    }
}