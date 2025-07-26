import java.io.*;

public class Main {

    static final String WOW = "WOW";

    static int findAll(String s) {
        int cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.substring(i).indexOf(WOW) == 0) {
                cnt++;
            }
        }
        return cnt;
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int Q = Integer.parseInt(br.readLine());
        while (Q-- > 0) {
            bw.write(findAll(br.readLine()) + "\n");
        }
        br.close();
        bw.flush();
        bw.close();
    }
}