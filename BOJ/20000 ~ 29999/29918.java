import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int productCount(int N, int M) {
        return N + 10 * M;
    }

    static int productCount(String N, String M) {
        return productCount(Integer.parseInt(N), Integer.parseInt(M));
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int adalbert = productCount(st.nextToken(), st.nextToken());
        int max = 0;
        for (int i = 0; i < 5; i++) {
            st = new StringTokenizer(br.readLine());
            max = Math.max(max, productCount(st.nextToken(), st.nextToken()));
        }
        System.out.println(max < adalbert ? 0 : max - adalbert + 1);
    }
}