import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        boolean[] idChar = new boolean[26];
        for (char c : br.readLine().toCharArray()) {
            idChar[c - 'a'] = true;
        }
        for (char c : br.readLine().toCharArray()) {
            if (idChar[c - 'a']) {
                continue;
            }
            bw.write(c);
        }
        br.close();
        bw.flush();
        bw.close();
    }
}