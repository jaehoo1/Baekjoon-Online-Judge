import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int stripes(String zebra) {

        int cou = 0;
        char[] chars = zebra.toCharArray();
        for (int i = 0; i < chars.length; i++) {
            if (i > 0 && chars[i] == '1' && chars[i - 1] == '0') {
                cou++;
            } else if (i == 0 && chars[i] == '1') {
                cou++;
            }
        }
        return cou;
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int L = Integer.parseInt(st.nextToken());

        int max = 0;
        String[] zebras = new String[N];
        for (int i = 0; i < N; i++) {
            zebras[i] = br.readLine();
            max = Math.max(max, stripes(zebras[i]));
        }
        int cou = 0;
        for (int i = 0; i < N; i++) {
            if (max == stripes(zebras[i])) {
                cou++;
            }
        }
        System.out.println(max + " " + cou);
    }
}