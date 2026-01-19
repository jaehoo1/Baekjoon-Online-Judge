import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int p = Integer.parseInt(br.readLine());
        boolean[] existing = new boolean[n + p];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n - 1; i++) {
            existing[Integer.parseInt(st.nextToken())] = true;
        }
        for (int i = p; i < n + p; i++) {
            if (!existing[i]) {
                System.out.println(i);
            }
        }
    }
}