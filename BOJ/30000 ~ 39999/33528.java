import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {

        String s = new BufferedReader(new InputStreamReader(System.in)).readLine();
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        for (int i = 0; i < 26; i++) {
            for (char c : s.toCharArray()) {
                c -= i;
                if (c < 'A') {
                    c += 26;
                }
                bw.write(c);
            }
            bw.write("\n");
        }
        bw.flush();
        bw.close();
    }
}