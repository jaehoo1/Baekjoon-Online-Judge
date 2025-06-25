import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        int[] ids = new int[N];
        for (int i = 0; i < N; i++) {
            ids[i] = Integer.parseInt(br.readLine());
        }
        int max = -1;
        Map<Integer, Integer> slidingWindow = new HashMap<>();
        for (int i = 0; i < K; i++) {
            if (slidingWindow.getOrDefault(ids[i], 0) > 0) {
                max = Math.max(max, ids[i]);
            }
            slidingWindow.put(ids[i], slidingWindow.getOrDefault(ids[i], 0) + 1);
        }
        for (int i = K; i < N; i++) {
            if (slidingWindow.getOrDefault(ids[i], 0) > 0) {
                max = Math.max(max, ids[i]);
            }
            slidingWindow.put(ids[i], slidingWindow.getOrDefault(ids[i], 0) + 1);
            if (slidingWindow.get(ids[i - K]) == 1) {
                slidingWindow.remove(ids[i - K]);
            } else {
                slidingWindow.put(ids[i - K], slidingWindow.get(ids[i - K]) - 1);
            }
        }
        System.out.println(max);
    }
}