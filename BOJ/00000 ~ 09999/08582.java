import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        int[] maxLeft = new int[n];
        int[] maxRight = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }
        for (int i = 0, max = 0; i < n; i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
            maxLeft[i] = max;
        }
        for (int i = n - 1, max = 0; i >= 0; i--) {
            if (arr[i] > max) {
                max = arr[i];
            }
            maxRight[i] = max;
        }
        for (int i = 0; i < n; i++) {
            bw.write(maxLeft[i] + " " + maxRight[i] + "\n");
        }
        bw.flush();
        br.close();
        bw.close();
    }
}