import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int boxCnt = 0;
        int boxWeight = 0;
        if (N == 0) {
            System.out.println(0);
            System.exit(0);
        }
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            int book = Integer.parseInt(st.nextToken());
            if (boxWeight + book > M) {
                boxWeight = 0;
                boxCnt++;
            }
            boxWeight += book;
        }
        if (boxWeight != 0) {
            boxCnt++;
        }
        System.out.println(boxCnt);
    }
}