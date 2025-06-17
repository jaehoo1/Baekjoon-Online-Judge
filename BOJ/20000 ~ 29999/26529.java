import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        long[] fibo = new long[46];
        fibo[0] = fibo[1] = 1;
        for (int i = 2; i <= 45; i++) {
            fibo[i] = fibo[i - 1] + fibo[i - 2];
        }
        int n = Integer.parseInt(br.readLine());
        while (n-- > 0) {
            bw.write(fibo[Integer.parseInt(br.readLine())] + "\n");
        }
        br.close();
        bw.flush();
        bw.close();
    }
}