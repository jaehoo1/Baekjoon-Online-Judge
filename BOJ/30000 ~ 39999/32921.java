import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int minTime(String time) {
        StringTokenizer st = new StringTokenizer(time, ":");
        return Integer.parseInt(st.nextToken()) * 60 + Integer.parseInt(st.nextToken());
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[] times = new int[n];
        for (int i = 0; i < n; i++) {
            times[i] = minTime(br.readLine());
        }
        for (int i = 0; i < n - 2; i++) {
            if (times[i + 2] - times[i] <= 10) {
                System.out.println(0);
                System.exit(0);
            }
        }
        for (int i = 0; i < n - 1; i++) {
            if (times[i + 1] - times[i] <= 10) {
                System.out.println(1);
                System.exit(0);
            }
        }
        System.out.println(2);
    }
}