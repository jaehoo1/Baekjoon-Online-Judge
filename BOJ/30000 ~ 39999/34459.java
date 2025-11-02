import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            int N = Integer.parseInt(br.readLine());
            int k;
            for (k = 1; Math.pow(5, k) < N; k++);
            bw.write("MIT" + (k > 1 ? "^" + k : "") + " time\n");
        }
        br.close();
        bw.flush();
        bw.close();
    }
}