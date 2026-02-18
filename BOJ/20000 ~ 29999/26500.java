import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        while (n-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            bw.write(String.format("%.1f\n", Math.abs(Double.parseDouble(st.nextToken()) - Double.parseDouble(st.nextToken()))));
        }
        br.close();
        bw.flush();
        bw.close();
    }
}