import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static void swap(boolean[] prize, int a, int b) {
        boolean temp = prize[a];
        prize[a] = prize[b];
        prize[b] = temp;
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        boolean[] prize = new boolean[n + 1];
        prize[Integer.parseInt(br.readLine())] = true;
        int m = Integer.parseInt(br.readLine());
        while (m-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            swap(prize, a, b);
        }
        for (int i = 1; i <= n; i++) {
            if (prize[i]) {
                System.out.println(i);
            }
        }
    }
}