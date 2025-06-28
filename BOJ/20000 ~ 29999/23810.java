import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws IOException {

        Scanner sc = new Scanner(System.in);
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = sc.nextInt();
        for (int i = 0; i < N; i++) {
            for (int k = 0; k < 5 * N; k++) {
                bw.write("@");
            }
            bw.write("\n");
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                bw.write("@");
            }
            bw.write("\n");
        }
        for (int i = 0; i < N; i++) {
            for (int k = 0; k < 5 * N; k++) {
                bw.write("@");
            }
            bw.write("\n");
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                bw.write("@");
            }
            bw.write("\n");
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                bw.write("@");
            }
            bw.write("\n");
        }

        bw.flush();
        bw.close();
    }
}