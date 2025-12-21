import java.io.*;

public class Main {

    static String getPosition(int term) {

        int i = 1, j = 1, rows = 1, iter = 1;
        while (iter < term) {
            if (i == 1 && rows % 2 == 1) {
                j++;
                rows++;
            } else if (j == 1 && rows % 2 == 0) {
                i++;
                rows++;
            } else {
                if (rows % 2 == 1) {
                    j++;
                    i--;
                } else {
                    i++;
                    j--;
                }
            }
            iter++;
        }
        return i + "/" + j;
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String line;
        while ((line = br.readLine()) != null) {
            int num = Integer.parseInt(line);
            bw.write("TERM " + num + " IS " + getPosition(num) + "\n");
        }
        br.close();
        bw.flush();
        bw.close();
    }
}