import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int half = n % 2 == 1 ? (n + 1) / 2 : n / 2;
        int cnt1 = 0;
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            if (Integer.parseInt(st.nextToken()) == 1) {
                cnt1++;
            }
        }
        System.out.println(cnt1 >= half ? 0 : half - cnt1);
    }
}