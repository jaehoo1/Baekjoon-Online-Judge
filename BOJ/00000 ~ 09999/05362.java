import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String line;
        while ((line = br.readLine()) != null) {
            while (line.contains("iiing")) {
                line = line.replace("iiing", "th");
            }
            bw.write(line + "\n");
        }
        br.close();
        bw.flush();
        bw.close();
    }
}