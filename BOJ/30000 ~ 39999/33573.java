import java.io.*;

public class Main {

    static boolean isSquare(long num) {
        long N = (long) Math.sqrt(num);
        return N * N == num;
    }

    static long reverse(long num) {
        String s = String.valueOf(num);
        StringBuilder sb = new StringBuilder();
        for (int i = s.length() - 1; i >= 0; i--) {
            sb.append(s.charAt(i));
        }
        return Long.parseLong(sb.toString());
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            long N = Long.parseLong(br.readLine());
            if (!isSquare(N) || !isSquare(reverse(N))) {
                bw.write("NO\n");
                continue;
            }
            bw.write("YES\n");
        }
        br.close();
        bw.flush();
        bw.close();
    }
}