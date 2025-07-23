import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int K = new Scanner(System.in).nextInt();
        for (int i = 0; i < K; i++) {
            for (int j = 0; j < K; j++) {
                bw.write('G');
            }
            for (int j = 0; j < 3 * K; j++) {
                bw.write('.');
            }
            bw.write("\n");
        }
        for (int i = 0; i < K; i++) {
            for (int j = 0; j < K; j++) {
                bw.write('.');
            }
            for (int j = 0; j < K; j++) {
                bw.write('I');
            }
            for (int j = 0; j < K; j++) {
                bw.write('.');
            }
            for (int j = 0; j < K; j++) {
                bw.write('T');
            }
            bw.write("\n");
        }
        for (int i = 0; i < K; i++) {
            for (int j = 0; j < 2 * K; j++) {
                bw.write('.');
            }
            for (int j = 0; j < K; j++) {
                bw.write('S');
            }
            for (int j = 0; j < K; j++) {
                bw.write('.');
            }
            bw.write("\n");
        }
        bw.flush();
        bw.close();
    }
}