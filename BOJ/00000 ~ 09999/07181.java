import java.io.*;

public class Main {

    static final int LEN = 4;

    static int A(String password, String s) {
        int result = 0;
        boolean[] digits = new boolean[10];
        for (int i = 0; i < LEN; i++) {
            digits[password.charAt(i) - '0'] = true;
        }
        for (int i = 0; i < LEN; i++) {
            if (digits[s.charAt(i) - '0']) {
                result++;
            }
        }
        return result;
    }

    static int B(String password, String s) {
        int result = 0;
        for (int i = 0; i < LEN; i++) {
            if (password.charAt(i) == s.charAt(i)) {
                result++;
            }
        }
        return result;
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String password = br.readLine();
        int N = Integer.parseInt(br.readLine());
        while (N-- > 0) {
            String num = br.readLine();
            bw.write(A(password, num) + " " + B(password, num) + "\n");
        }
        br.close();
        bw.flush();
        bw.close();
    }
}