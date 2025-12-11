import java.io.*;
import java.util.StringTokenizer;

public class Main {

    static double[] x, y;

    static double dist(int i, int j) {
        return Math.sqrt(Math.pow(x[i] - x[j], 2) + Math.pow(y[i] - y[j], 2));
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            double d = Double.parseDouble(st.nextToken());
            int N = Integer.parseInt(st.nextToken());
            if (d == 0 && N == 0) {
                break;
            }
            int fights = 0;
            x = new double[N];
            y = new double[N];
            for (int i = 0; i < N; i++) {
                st = new StringTokenizer(br.readLine());
                x[i] = Double.parseDouble(st.nextToken());
                y[i] = Double.parseDouble(st.nextToken());
            }
            for (int i = 0; i < N; i++) {
                boolean fight = false;
                for (int j = 0; j < N; j++) {
                    if (i == j) {
                        continue;
                    }
                    if (dist(i, j) <= d) {
                        fight = true;
                        break;
                    }
                }
                if (fight) {
                    fights++;
                }
            }
            bw.write(fights + " sour, " + (N - fights) + " sweet\n");
        }
        br.close();
        bw.flush();
        bw.close();
    }
}