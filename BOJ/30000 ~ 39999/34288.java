import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int l = Integer.parseInt(st.nextToken());
        int a = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int cur = Integer.parseInt(st.nextToken());
        while (l-- > 0) {
            int next = Integer.parseInt(st.nextToken());
            if (next - cur > a) {
                System.out.println("BUG REPORT");
                System.exit(0);
            }
            cur = next;
        }
        System.out.println("POSSIBLE");
    }
}