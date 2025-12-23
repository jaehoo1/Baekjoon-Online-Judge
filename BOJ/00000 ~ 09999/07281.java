import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int lastInternet = 1;
        int maxTime = 0;
        while (N-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int T = Integer.parseInt(st.nextToken());
            int M = Integer.parseInt(st.nextToken());
            if (M == 1) {
                maxTime = Math.max(maxTime, T - lastInternet);
                lastInternet = T;
            }
        }
        System.out.println(maxTime);
    }
}