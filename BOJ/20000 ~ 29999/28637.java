import java.io.*;

public class Main {

    static boolean isUpperCase(char c) {
        return c >= 'A' && c <= 'Z';
    }

    static char toLowerCase(char c) {
        return (char) (c + 32);
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());
        while (n-- > 0) {
            String s = br.readLine();
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < s.length(); i++) {
                char c = s.charAt(i);
                if (isUpperCase(c)) {
                    if (i != 0) {
                        sb.append("_");
                    }
                    sb.append(toLowerCase(c));
                } else {
                    sb.append(c);
                }
            }
            bw.write(sb + "\n");
        }
        br.close();
        bw.flush();
        bw.close();
    }
}