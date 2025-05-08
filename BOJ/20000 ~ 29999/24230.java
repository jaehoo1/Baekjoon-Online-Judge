import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    static int[] color;
    static List<Integer>[] edges;
    static boolean[] visited;
    static int result;

    static void dfs(int node, int parent) {
        visited[node] = true;
        if (color[node] != color[parent]) {
            result++;
        }
        for (int i = 0; i < edges[node].size(); i++) {
            int next = edges[node].get(i);
            if (visited[next]) {
                continue;
            }
            dfs(next, node);
        }
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        edges = new ArrayList[N + 1];
        color = new int[N + 1];
        visited = new boolean[N + 1];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            edges[i] = new ArrayList<>();
            color[i] = Integer.parseInt(st.nextToken());
        }
        for (int i = 0; i < N - 1; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            edges[u].add(v);
            edges[v].add(u);
        }
        dfs(1, 1);
        System.out.println(color[1] == 0 ? result : result + 1);
    }
}