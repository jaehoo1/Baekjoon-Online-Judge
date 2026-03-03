import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int x = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[] crates = new int[n + 1];
        for (int i = 0; i < m; i++) {
            crates[Integer.parseInt(br.readLine())]++;
        }
        System.out.println(Math.min(
                Arrays.stream(crates, 1, x)
                        .sum(),
                m - Arrays.stream(crates, 1, x)
                        .sum()
        ));
    }
}