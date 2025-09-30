import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int T = Integer.MIN_VALUE;
        int B = Integer.MAX_VALUE;
        while (N-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            T = Math.max(T, Integer.parseInt(st.nextToken()));
            B = Math.min(B, Integer.parseInt(st.nextToken()));
        }
        System.out.println(T * B % 7 + 1);
    }
}