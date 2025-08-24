import java.io.*;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {

    static final Map<Character, String> map = Map.of(
            'd', "dqb",
            'b', "bpd",
            'q', "qdp",
            'p', "pbq"
    );

    static char flip(char c, int vector) {
        return map.get(c).charAt(vector);
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int D = Integer.parseInt(st.nextToken());
        for (int i = 0; i < N; i++) {
            for (char c : br.readLine().toCharArray()) {
                bw.write(flip(c, D));
            }
            bw.write("\n");
        }
        br.close();
        bw.flush();
        bw.close();
    }
}