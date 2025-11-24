import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String line;
        while ((line = br.readLine()) != null) {
            StringTokenizer st = new StringTokenizer(line);
            int[] arr = new int[st.countTokens()];
            for (int i = 0; i < arr.length; i++) {
                arr[i] = Integer.parseInt(st.nextToken());
            }
            for (int i = 0; i < arr.length; i++) {
                int scaled = 1;
                for (int j = -1; j <= 1; j++) {
                    int next = i + j;
                    if (next < 0 || next >= arr.length) {
                        continue;
                    }
                    scaled *= arr[next];
                }
                bw.write(scaled + " ");
            }
            bw.write("\n");
        }
        br.close();
        bw.flush();
        bw.close();
    }
}