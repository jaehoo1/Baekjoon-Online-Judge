import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        while (N-- > 0) {
            int sum = 0;
            br.readLine();
            StringTokenizer st = new StringTokenizer(br.readLine());
            while (st.hasMoreTokens()) {
                String s = st.nextToken();
                if (s.equals("+")) {
                    continue;
                }
                if (s.equals("!")) {
                    s = "9";
                }
                sum += Integer.parseInt(s);
            }
            bw.write((sum > 9 ? "!" : sum) + "\n");
        }
        br.close();
        bw.flush();
        bw.close();
    }
}