import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Optional;
import java.util.SortedMap;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        SortedMap<Integer, Integer> map = new TreeMap<>();

        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            int key = Integer.parseInt(st.nextToken());
            map.put(key, map.containsKey(key) ? map.get(key) + 1 : 1);
        }

        int cnt = 0;
        while (N-- > 0) {
            if (map.size() <= 1) {
                break;
            }
            int minMatCnt = map.values().stream().min(Integer::compareTo).get();
            map.replaceAll((k, v) ->
                    map.get(k) - minMatCnt);
            map.entrySet()
                    .removeIf(entry -> entry.getValue() == 0);
            cnt += minMatCnt;
        }
        System.out.println(cnt + map.values().stream().mapToInt(Integer::intValue).sum());
    }
}