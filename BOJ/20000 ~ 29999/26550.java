import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        while (n-- > 0) {
            long cnt = 0;
            int num = Integer.parseInt(br.readLine());
            for (int i = 1; i <= num; i++) {
                cnt += (long) i * (num - i + 1);
            }
            bw.write(cnt + "\n");
        }
        br.close();
        bw.flush();
        bw.close();
    }
}