import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int sellable = 0;
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        int P = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            int nonCream = 0;
            for (int j = 0; j < K; j++) {
                if ("0".equals(st.nextToken())) {
                    nonCream++;
                }
            }
            if (nonCream < P) {
                sellable++;
            }
        }
        System.out.println(sellable);
    }
}