import java.io.*;
import java.util.Arrays;

public class Main {

    static void reverse(char[] chars) {

        for (int i = 0; i < chars.length / 2; i++) {
            char c = chars[i];
            chars[i] = chars[chars.length - 1 - i];
            chars[chars.length - 1 - i] = c;
        }
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            br.readLine();
            char[] chars = br.readLine().toCharArray();
            Arrays.sort(chars);
            reverse(chars);
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < chars.length - 1; i++) {
                sb.append(chars[i]);
            }
            bw.write((Long.parseLong(sb.toString()) + Integer.parseInt(String.valueOf(chars[chars.length - 1]))) + "\n");
        }
        br.close();
        bw.flush();
        bw.close();
    }
}