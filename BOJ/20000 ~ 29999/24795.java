import java.io.*;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        Set<Integer> set = new HashSet<>();
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int Y = Integer.parseInt(st.nextToken());
        while (Y-- > 0) {
            set.add(Integer.parseInt(br.readLine()));
        }
        for (int i = 0; i < N; i++) {
            if (set.contains(i)) {
                continue;
            }
            bw.write(i + "\n");
        }
        bw.write("Mario got " + set.size() + " of the dangerous obstacles.");
        br.close();
        bw.flush();
        bw.close();
    }
}