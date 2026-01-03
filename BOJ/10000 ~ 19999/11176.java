import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            int emptyBottle = 0;
            StringTokenizer st = new StringTokenizer(br.readLine());
            int E = Integer.parseInt(st.nextToken());
            int N = Integer.parseInt(st.nextToken());
            while (N-- > 0) {
                if (Integer.parseInt(br.readLine()) > E) {
                    emptyBottle++;
                }
            }
            bw.write(emptyBottle + "\n");
        }
        br.close();
        bw.flush();
        bw.close();
    }
}