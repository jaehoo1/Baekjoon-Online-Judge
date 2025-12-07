import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        arr[0] = 1;
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 1; i < n; i++) {
            arr[Integer.parseInt(st.nextToken()) + 1] = i + 1;
        }
        for (int i = 0; i < n; i++) {
            bw.write(arr[i] + " ");
        }
        br.close();
        bw.flush();
        bw.close();
    }
}