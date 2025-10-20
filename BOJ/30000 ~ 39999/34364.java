import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        StringTokenizer st = new StringTokenizer(new BufferedReader(new InputStreamReader(System.in)).readLine());
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        st.nextToken();
        String letters = st.nextToken();
        long shift = 1;
        for (int i = 0; i < letters.length(); i++) {
            long c = letters.charAt(i);
            c += shift % 26;
            shift *= 2;
            while (c > 'Z') {
                c -= 26;
            }
            bw.write((char) c);
        }
        bw.flush();
        bw.close();
    }
}