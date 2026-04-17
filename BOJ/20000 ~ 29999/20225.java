import java.io.*;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int m = Integer.parseInt(st.nextToken());
            int n = Integer.parseInt(st.nextToken());
            int p = Integer.parseInt(st.nextToken());
            if (m == 0 && n == 0 && p == 0) {
                break;
            }
            Set<Integer> virus = new HashSet<>();
            virus.add(p);
            while (n-- > 0) {
                st = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                if (virus.contains(a) || virus.contains(b)) {
                    virus.add(a);
                    virus.add(b);
                }
            }
            bw.write(virus.size() + "\n");
        }
        br.close();
        bw.flush();
        bw.close();
    }
}