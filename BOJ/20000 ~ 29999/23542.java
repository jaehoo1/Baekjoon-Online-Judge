import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[] iqs = new int[n * 2];
        int[] teams = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n * 2; i++) {
            iqs[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(iqs);
        for (int i = 0; i < n; i++) {
            teams[i] = iqs[i] + iqs[2 * n - 1 - i];
        }
        Arrays.sort(teams);
        System.out.println(teams[n - 1] - teams[0]);
    }
}