import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int streak = 0, maxStreak = 0;
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            int si = Integer.parseInt(st.nextToken());
            if (si > 0) {
                streak++;
            } else {
                maxStreak = Math.max(maxStreak, streak);
                streak = 0;
            }
        }
        maxStreak = Math.max(maxStreak, streak);
        System.out.println(maxStreak);
    }
}