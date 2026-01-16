import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            int N = Integer.parseInt(br.readLine());
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (j == 0 || j == N - 1) {
                        bw.write("#");
                    } else if (i > N / 2) {
                        bw.write(".");
                    } else if (j == i || j == N - 1 - i) {
                        bw.write("#");
                    } else {
                        bw.write(".");
                    }
                }
                bw.write("\n");
            }
        }
        br.close();
        bw.flush();
        bw.close();
    }
}