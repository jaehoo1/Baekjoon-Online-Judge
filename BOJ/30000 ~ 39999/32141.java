import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int H = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int i;
        for (i = 0; i < N && H > 0; i++) {
            H -= Integer.parseInt(st.nextToken());
        }
        System.out.println(H <= 0 ? i : -1);
    }
}