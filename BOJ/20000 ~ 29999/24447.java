import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int N;
    static List<Integer>[] edges;
    static int[] depths;
    static int[] traversalOrders;

    static long bfs(int start) {

        boolean[] visited = new boolean[N + 1];
        int order = 1;
        Queue<Integer> queue = new LinkedList<>();
        visited[start] = true;
        depths[start] = 0;
        traversalOrders[start] = order++;
        queue.offer(start);
        while (!queue.isEmpty()) {
            int cur = queue.poll();
            for (int i = 0; i < edges[cur].size(); i++) {
                int next = edges[cur].get(i);
                if (visited[next]) {
                    continue;
                }
                visited[next] = true;
                depths[next] = depths[cur] + 1;
                traversalOrders[next] = order++;
                queue.offer(next);
            }
        }
        long result = 0;
        for (int i = 1; i <= N; i++) {
            result += (long) depths[i] * traversalOrders[i];
        }
        return result;
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int R = Integer.parseInt(st.nextToken());
        edges = new List[N + 1];
        depths = new int[N + 1];
        traversalOrders = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            edges[i] = new ArrayList<>();
        }
        Arrays.fill(depths, -1);
        Arrays.fill(traversalOrders, 0);
        while (M-- > 0) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            edges[u].add(v);
            edges[v].add(u);
        }
        for (int i = 1; i <= N; i++) {
            Collections.sort(edges[i]);
        }
        System.out.println(bfs(R));
    }
}