import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        while (n-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            double A1 = Integer.parseInt(st.nextToken());
            double P1 = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(br.readLine());
            double R1 = Integer.parseInt(st.nextToken());
            double P2 = Integer.parseInt(st.nextToken());
            bw.write((A1 / P1) > (R1 * R1 * Math.PI / P2) ? "Slice of pizza\n" : "Whole pizza\n");
        }
        br.close();
        bw.flush();
        bw.close();
    }
}