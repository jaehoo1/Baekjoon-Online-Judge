import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int K = new Scanner(System.in).nextInt();
        StringBuilder sb = new StringBuilder("AKA");
        for (int i = 0; i < K; i++) {
            sb.append("RAKA");
        }
        bw.write(sb.toString());
        bw.flush();
        bw.close();
    }
}