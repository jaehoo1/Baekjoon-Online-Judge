import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String line;
        while ((line = br.readLine()) != null) {
            for (int i = 0; i < line.length(); i++) {
                char c = line.charAt(i);
                if (c == 'i') {
                    bw.write('e');
                } else if (c == 'e') {
                    bw.write('i');
                } else if (c == 'I') {
                    bw.write('E');
                } else if (c == 'E') {
                    bw.write('I');
                } else {
                    bw.write(c);
                }
            }
            bw.write("\n");
        }
        br.close();
        bw.flush();
        bw.close();
    }
}