import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static double distance(int R, int C, int M) {
        return R + Math.abs((double) (M + 1) / 2 - C);
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        double minDist = Double.MAX_VALUE;
        int minR = -1, minC = -1;
        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= M; j++) {
                if (st.nextToken().equals("1")) {
                    continue;
                }
                double dist = distance(i, j, M);
                if (dist < minDist) {
                    minDist = dist;
                    minR = i;
                    minC = j;
                }
            }
        }
        System.out.println(minR == -1 && minC == -1 ? -1 : minR + " " + minC);
    }
}