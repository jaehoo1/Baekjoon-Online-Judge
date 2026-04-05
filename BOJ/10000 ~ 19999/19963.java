import java.io.*;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.stream.Collectors;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        Set<Integer> set = new HashSet<>();
        for (int i = 1; i <= n; i++) {
            set.add(i);
        }
        st = new StringTokenizer(br.readLine());
        while (m-- > 0) {
            set.remove(Integer.parseInt(st.nextToken()));
        }
        st = new StringTokenizer(br.readLine());
        while (k-- > 0) {
            set.remove(Integer.parseInt(st.nextToken()));
        }
        bw.write(set.size() + "\n");
        bw.write(
                set.stream()
                        .map(String::valueOf)
                        .collect(Collectors.joining(" "))
        );
        br.close();
        bw.flush();
        bw.close();
    }
}