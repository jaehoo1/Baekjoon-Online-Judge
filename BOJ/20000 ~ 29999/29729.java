import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int S = Integer.parseInt(st.nextToken());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int U = 0;
        while (N + M > 0) {
            int cmd = Integer.parseInt(br.readLine());
            if (cmd == 0) {
                U--;
                M--;
            } else if (cmd == 1) {
                if (U == S) {
                    S *= 2;
                }
                U++;
                N--;
            }
        }
        System.out.println(S);
    }
}