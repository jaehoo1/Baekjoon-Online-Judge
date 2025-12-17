import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        while (n-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            double area = Double.parseDouble(st.nextToken());
            double base = Double.parseDouble(st.nextToken());
            bw.write("The height of the triangle is " + String.format("%.2f", area * 2 / base) + " units\n");
        }
        br.close();
        bw.flush();
        bw.close();
    }
}