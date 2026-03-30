import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int m = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(st.nextToken());
        boolean[] fences = new boolean[m + 1];
        while (n-- > 0) {
            st = new StringTokenizer(br.readLine());
            int l = Integer.parseInt(st.nextToken());
            int r = Integer.parseInt(st.nextToken());
            for (int i = l; i <= r; i++) {
                fences[i] = true;
            }
        }
        boolean allCovered = true;
        for (int i = 1; i <= m; i++) {
            if (!fences[i]) {
                allCovered = false;
            }
        }
        System.out.println(allCovered ? "YES" : "NO");
    }
}