import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        int[] forces = new int[n];
        long sum = 0;
        int bossIdx = -1;
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            forces[i] = Integer.parseInt(st.nextToken());
            sum += forces[i];
        }
        for (int i = 0; i < n; i++) {
            if (sum - forces[i] == forces[i]) {
                bossIdx = i;
            }
        }
        for (int i = 0; i < n; i++) {
            if (bossIdx != i) {
                bw.write(forces[i] + " ");
            }
        }
        bw.write("" + forces[bossIdx]);
        br.close();
        bw.flush();
        bw.close();
    }
}