import java.io.*;

public class Main {

    static boolean isOdd(int num) {
        return num % 2 == 1;
    }

    static boolean isSquare(int num) {
        int sqrt = (int) Math.sqrt(num);
        return sqrt * sqrt == num;
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            int N = Integer.parseInt(br.readLine());
            StringBuilder sb = new StringBuilder();
            if (isOdd(N)) {
                sb.append("O");
            }
            if (isSquare(N)) {
                sb.append("S");
            }
            if (sb.length() == 0) {
                sb.append("EMPTY");
            }
            sb.append("\n");
            bw.write(sb.toString());
        }
        br.close();
        bw.flush();
        bw.close();
    }
}