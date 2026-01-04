import java.io.*;

public class Main {

    static int find(int[] arr) {
        for (int i = 0; i < 26; i++) {
            if (arr[i] > 0) {
                return i;
            }
        }
        return -1;
    }

    static void addLetter(StringBuilder sb, int idx, int[] a, int[] b) {
        if (a[idx] > 0) {
            a[idx]--;
        }
        if (b[idx] > 0) {
            b[idx]--;
        }
        sb.append((char) ('a' + idx));
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringBuilder sb = new StringBuilder();
        int[] a = new int[26];
        int[] b = new int[26];
        for (char c : br.readLine().toCharArray()) {
            a[c - 'a']++;
        }
        for (char c : br.readLine().toCharArray()) {
            b[c - 'a']++;
        }
        while (true) {
            int idx = find(a);
            if (idx == -1) {
                idx = find(b);
            }
            if (idx == -1) {
                break;
            }
            addLetter(sb, idx, a, b);
        }
        bw.write(sb.toString());
        br.close();
        bw.flush();
        bw.close();
    }
}