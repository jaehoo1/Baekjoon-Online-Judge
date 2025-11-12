import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static double areaOfTrapezoid(int a, int b, int h) {
        return (double) (a + b) * h / 2;
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[] heights = new int[N + 1];
        int[] widths = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N + 1; i++) {
            heights[i] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            widths[i] = Integer.parseInt(st.nextToken());
        }
        double totalArea = 0;
        for (int i = 0; i < N; i++) {
            totalArea += areaOfTrapezoid(heights[i], heights[i + 1], widths[i]);
        }
        System.out.printf("%.7f", totalArea);
    }
}