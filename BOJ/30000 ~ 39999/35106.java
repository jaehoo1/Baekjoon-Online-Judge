import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;
import java.util.stream.IntStream;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        Map<Integer, Integer> map = new HashMap<>();
        IntStream.rangeClosed(1, 3)
                .forEach(i -> map.put(i, 0));
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N * 3; i++) {
            map.compute(Integer.valueOf(st.nextToken()), (k, v) -> v == null ? 1 : v + 1);
        }
        System.out.println(map.entrySet().stream().filter(entry -> entry.getValue() == N - 1).findFirst().get().getKey());
        System.out.println(map.entrySet().stream().filter(entry -> entry.getValue() == N + 1).findFirst().get().getKey());
    }
}