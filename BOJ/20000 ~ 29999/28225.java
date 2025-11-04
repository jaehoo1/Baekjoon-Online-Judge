import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int remainedDistance(int lenOfStreet, int location) {
        return lenOfStreet - location;
    }

    static double remainedTime(int remainedDistance, int speed) {
        return (double) remainedDistance / speed;
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int f = Integer.parseInt(st.nextToken());
        double min = Double.MAX_VALUE;
        int num = 0;
        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            double time = remainedTime(remainedDistance(f, x), v);
            if (time < min) {
                min = time;
                num = i;
            }
        }
        System.out.println(num);
    }
}