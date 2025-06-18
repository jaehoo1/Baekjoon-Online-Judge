import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int B = 0, S = 0, A = 0;
        String string = br.readLine();
        for (int i = 0; i < N; i++) {
            char c = string.charAt(i);
            if (c == 'B') {
                B++;
            } else if (c == 'S') {
                S++;
            } else if (c == 'A') {
                A++;
            }
        }
        int max = Math.max(Math.max(B, S), A);
        if (max == B && max == S && max == A) {
            System.out.println("SCU");
        } else if (max == B && max == S) {
            System.out.println("BS");
        } else if (max == B && max == A) {
            System.out.println("BA");
        } else if (max == S && max == A) {
            System.out.println("SA");
        } else if (max == B) {
            System.out.println("B");
        } else if (max == S) {
            System.out.println("S");
        } else if (max == A) {
            System.out.println("A");
        }
    }
}