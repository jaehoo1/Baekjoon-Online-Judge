import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            int N = Integer.parseInt(br.readLine());
            bw.write((Math.pow((int) Math.sqrt(N), 2) == N ? 1 : 0) + "\n");
        }
        br.close();
        bw.flush();
        bw.close();
    }
}