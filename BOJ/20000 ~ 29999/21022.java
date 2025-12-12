import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[] scores = new int[N];
        int[] opponent = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            scores[i] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            opponent[i] = Integer.parseInt(st.nextToken());
        }
        int score = 0;
        for (int i = 0; i < N; i++) {
            if (scores[i] > opponent[i]) {
                score += 3;
            } else if (scores[i] == opponent[i]) {
                score++;
            }
        }
        System.out.println(score);
    }
}