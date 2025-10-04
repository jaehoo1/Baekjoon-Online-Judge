import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {

        String string = new BufferedReader(new InputStreamReader(System.in)).readLine();
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        for (char c : string.toCharArray()) {
            if (c >= 'a' && c <= 'z') {
                bw.write(String.format("%02d", c - 'a' + 1));
            } else if (c >= 'A' && c <= 'Z') {
                bw.write(String.valueOf(c - 'A' + 27));
            } else if (c >= '0' && c <= '9') {
                bw.write("#" + c);
            } else {
                bw.write(c);
            }
        }
        bw.flush();
        bw.close();
    }
}