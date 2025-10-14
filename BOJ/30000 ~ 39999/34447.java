import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int k = Integer.parseInt(st.nextToken());
            String n = st.nextToken();
            for (int i = 0; i < n.length(); i++) {
                char c = (char) (n.charAt(i) + k);
                if (c > '9') {
                    c -= 10;
                }
                bw.write(c);
            }
            bw.write("\n");
        }
        br.close();
        bw.flush();
        bw.close();
    }
}