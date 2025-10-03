import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        String[] badWords = new String[N];
        for (int i = 0; i < N; i++) {
            badWords[i] = br.readLine();
        }
        while (M-- > 0) {
            boolean isBadWord = false;
            char[] chars = br.readLine().toCharArray();
            for (int i = 0; i < chars.length; i++) {
                if (chars[i] == '0') {
                    chars[i] = 'O';
                } else if (chars[i] == '1') {
                    chars[i] = 'L';
                } else if (chars[i] == '2') {
                    chars[i] = 'Z';
                } else if (chars[i] == '3') {
                    chars[i] = 'E';
                } else if (chars[i] == '5') {
                    chars[i] = 'S';
                } else if (chars[i] == '6') {
                    chars[i] = 'B';
                } else if (chars[i] == '7') {
                    chars[i] = 'T';
                } else if (chars[i] == '8') {
                    chars[i] = 'B';
                }
            }
            String plate = new String(chars);
            for (int i = 0; i < N; i++) {
                if (plate.contains(badWords[i])) {
                    isBadWord = true;
                    break;
                }
            }
            bw.write(isBadWord ? "INVALID\n" : "VALID\n");
        }
        br.close();
        bw.flush();
        bw.close();
    }
}