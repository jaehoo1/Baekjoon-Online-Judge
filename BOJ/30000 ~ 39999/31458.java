import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            String s = br.readLine().replace("0!", "1");
            while (s.contains("1!")) {
                s = s.replace("1!", "1");
            }
            while (s.contains("!!")) {
                s = s.replace("!!", "");
            }
            s = s.replace("!0", "1");
            s = s.replace("!1", "0");
            bw.write(s + "\n");
        }
        br.close();
        bw.flush();
        bw.close();
    }
}