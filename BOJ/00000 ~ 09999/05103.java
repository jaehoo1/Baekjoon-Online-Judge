import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        while (true) {
            String stockCode = br.readLine();
            if (stockCode.equals("#")) {
                break;
            }
            StringTokenizer st = new StringTokenizer(br.readLine());
            int M = Integer.parseInt(st.nextToken());
            int S = Integer.parseInt(st.nextToken());
            int T = Integer.parseInt(br.readLine());
            while (T-- > 0) {
                st = new StringTokenizer(br.readLine());
                String letter = st.nextToken();
                int num = Integer.parseInt(st.nextToken());
                if (letter.equals("S")) {
                    if (S - num >= 0) {
                        S -= num;
                    }
                } else if (letter.equals("R")) {
                    if (S + num <= M) {
                        S += num;
                    }
                }
            }
            bw.write(stockCode + " " + S + "\n");
        }
        br.close();
        bw.flush();
        bw.close();
    }
}