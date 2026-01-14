import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        Map<Integer, Integer> map = new HashMap<>();
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        while (N-- > 0) {
            map.compute(Integer.parseInt(br.readLine()), (k, v) -> v == null ? 1 : v + 1);
        }
        System.out.println(map.entrySet().stream().filter(entry -> entry.getValue() % K != 0).findFirst().get().getKey());
    }
}