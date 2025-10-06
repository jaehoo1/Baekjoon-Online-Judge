import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        String[] D = new String[N];
        int[] C = new int[N];
        int jinju = -1;
        int count = 0;
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            D[i] = st.nextToken();
            C[i] = Integer.parseInt(st.nextToken());
            if (D[i].equals("jinju")) {
                jinju = i;
            }
        }
        for (int i = 0; i < N; i++) {
            if (C[i] > C[jinju]) {
                count++;
            }
        }
        System.out.println(C[jinju]);
        System.out.println(count);
    }
}