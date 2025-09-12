import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int streak = 0;
        int maxStreak = 0;
        while (N-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int S = Integer.parseInt(st.nextToken());
            int T = Integer.parseInt(st.nextToken());
            if (S > T) {
                streak++;
            } else {
                streak = 0;
            }
            maxStreak = Math.max(maxStreak, streak);
        }
        System.out.println(maxStreak);
    }
}