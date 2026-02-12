import java.io.*;
import java.util.stream.IntStream;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        while (true) {
            double num = Double.parseDouble(br.readLine());
            if (num == 0) {
                break;
            }
            bw.write(String.format("%.2f\n", IntStream.rangeClosed(0, 4)
                    .mapToDouble(i -> Math.pow(num, i))
                    .sum()));
        }
        br.close();
        bw.flush();
        bw.close();
    }
}