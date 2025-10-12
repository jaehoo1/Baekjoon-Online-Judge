import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int M = Integer.parseInt(br.readLine());
        int max = 0, min = Integer.MAX_VALUE;
        int maxSum = 0, minSum = Integer.MAX_VALUE;
        while (M-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int S = Integer.parseInt(st.nextToken());
            int sum = 0;
            while (S-- > 0) {
                int score = Integer.parseInt(st.nextToken());
                max = Math.max(max, score);
                min = Math.min(min, score);
                sum += score;
            }
            maxSum = Math.max(maxSum, sum);
            minSum = Math.min(minSum, sum);
        }
        System.out.printf("%d\n%d\n%d\n%d", max, min, maxSum, minSum);
    }
}