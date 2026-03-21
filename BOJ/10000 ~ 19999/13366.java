import java.io.*;

public class Main {

    static boolean isMultipleOf9(String s) {
        int sum = 0;
        for (char c : s.toCharArray()) {
            sum += c - '0';
        }
        return sum % 9 == 0;
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            bw.write(isMultipleOf9(br.readLine()) ? "YES\n" : "NO\n");
        }
        br.close();
        bw.flush();
        bw.close();
    }
}