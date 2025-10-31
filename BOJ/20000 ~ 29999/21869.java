import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = new Scanner(System.in).nextInt();
        bw.write(N == 1 ? "1\n" : 2 * N - 2 + "\n");
        for (int i = 1; i <= N; i++) {
            bw.write(i + " 1\n");
            if (i != 1 && i != N) {
                bw.write(i + " " + N + "\n");
            }
        }
        bw.flush();
        bw.close();
    }
}
