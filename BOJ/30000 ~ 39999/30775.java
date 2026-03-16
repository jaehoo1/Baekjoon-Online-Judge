import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int M = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        long sum = 0;
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < K; i++) {
            sum += Integer.parseInt(st.nextToken());
        }
        System.out.println((sum / M) + (sum % M == 0 ? 0 : 1));
    }
}