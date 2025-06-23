import java.io.*;

public class Main {

    static int recurCnt;

    static int recursion(String s, int l, int r) {
        recurCnt++;
        if (l >= r) {
            return 1;
        } else if (s.charAt(l) != s.charAt(r)) {
            return 0;
        }
        return recursion(s, l + 1, r - 1);
    }

    static int isPalindrome(String s) {
        return recursion(s, 0, s.length() - 1);
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            recurCnt = 0;
            bw.write(isPalindrome(br.readLine()) + " " + recurCnt + "\n");
        }
        br.close();
        bw.flush();
        bw.close();
    }
}