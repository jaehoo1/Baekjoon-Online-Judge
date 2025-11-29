import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static boolean isValidTraiangle(int[] triangle1, int[] triangle2) {
        Arrays.sort(triangle1);
        Arrays.sort(triangle2);
        for (int i = 0; i < 3; i++) {
            if (triangle1[i] != triangle2[i]) {
                return false;
            }
        }
        return triangle1[0] * triangle1[0] + triangle1[1] * triangle1[1] == triangle1[2] * triangle1[2];
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        while (n-- > 0) {
            int[] triangle1 = new int[3];
            int[] triangle2 = new int[3];
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 0; i < 3; i++) {
                triangle2[i] = Integer.parseInt(st.nextToken());
            }
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < 3; i++) {
                triangle1[i] = Integer.parseInt(st.nextToken());
            }
            bw.write(isValidTraiangle(triangle1, triangle2) ? "YES\n" : "NO\n");
        }
        br.close();
        bw.flush();
        bw.close();
    }
}