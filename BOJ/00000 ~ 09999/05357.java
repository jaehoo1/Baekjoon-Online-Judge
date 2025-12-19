import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            char[] chars = br.readLine().toCharArray();
            for (int i = 0; i < chars.length; i++) {
                if (i > 0 && chars[i] == chars[i - 1]) {
                    continue;
                }
                bw.write(chars[i]);
            }
            bw.write("\n");
        }
        br.close();
        bw.flush();
        bw.close();
    }
}