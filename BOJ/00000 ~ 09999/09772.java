import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            double x = Double.parseDouble(st.nextToken());
            double y = Double.parseDouble(st.nextToken());
            if (x == 0 || y == 0) {
                bw.write("AXIS\n");
            } else if (x > 0) {
                bw.write(y > 0 ? "Q1\n" : "Q4\n");
            } else if (x < 0) {
                bw.write(y > 0 ? "Q2\n" : "Q3\n");
            }
            if (x == 0 && y == 0) {
                break;
            }
        }
        br.close();
        bw.flush();
        bw.close();
    }
}