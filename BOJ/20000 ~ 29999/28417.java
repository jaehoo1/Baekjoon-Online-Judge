import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int max = Integer.MIN_VALUE;
        while (N-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int score = Math.max(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
            Integer[] tricks = new Integer[5];
            for (int i = 0; i < 5; i++) {
                tricks[i] = Integer.parseInt(st.nextToken());
            }
            Arrays.sort(tricks);
            score += tricks[3] + tricks[4];
            max = Math.max(max, score);
        }
        System.out.println(max);
    }
}