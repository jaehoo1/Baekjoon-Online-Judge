import java.io.*;
import java.util.StringTokenizer;

public class Main {

    static int query1(char[] chars, int l, int r) {
        l--;
        r--;
        int cnt = 1;
        for (int i = l + 1; i <= r; i++) {
            if (chars[i] != chars[i - 1]) {
                cnt++;
            }
        }
        return cnt;
    }

    static void query2(char[] chars, int l, int r) {
        l--;
        r--;
        while (l <= r) {
            chars[l]++;
            if (chars[l] > 'Z') {
                chars[l] = 'A';
            }
            l++;
        }
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        st.nextToken();
        int Q = Integer.parseInt(st.nextToken());
        char[] S = br.readLine().toCharArray();
        while (Q-- > 0) {
            st = new StringTokenizer(br.readLine());
            int cmd = Integer.parseInt(st.nextToken());
            int l = Integer.parseInt(st.nextToken());
            int r = Integer.parseInt(st.nextToken());
            if (cmd == 1) {
                bw.write(query1(S, l, r) + "\n");
            } else if (cmd == 2) {
                query2(S, l, r);
            }
        }
        br.close();
        bw.flush();
        bw.close();
    }
}