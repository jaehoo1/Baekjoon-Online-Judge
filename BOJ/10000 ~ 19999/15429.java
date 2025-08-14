import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        while (n-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int g = Integer.parseInt(st.nextToken());
            int[] arr = new int[g];
            for (int i = 0; i < g; i++) {
                arr[i] = Integer.parseInt(st.nextToken());
            }
            for (int i = 1; i < g - 1; i++) {
                if (arr[i - 1] + 1 != arr[i]) {
                    bw.write((i + 1) + "\n");
                    break;
                }
            }
        }
        br.close();
        bw.flush();
        bw.close();
    }
}