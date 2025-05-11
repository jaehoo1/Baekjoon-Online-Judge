import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    static List<Integer>[] edges;
    static boolean[][] visited;
    static int[][] dp;

    static int dfs(int node, int parent, boolean isEarlyAdopter) {

        int earlyAdopter = isEarlyAdopter ? 1 : 0;
        if (visited[node][earlyAdopter]) {
            return dp[node][earlyAdopter];
        }

        visited[node][earlyAdopter] = true;
        for (int next : edges[node]) {
            if (next == parent) {
                continue;
            }
            dp[node][earlyAdopter] += Math.min(isEarlyAdopter ? dfs(next, node, false) : Integer.MAX_VALUE, dfs(next, node, true));
        }
        return dp[node][earlyAdopter] += earlyAdopter;
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        edges = new ArrayList[N + 1];
        for (int i = 1; i <= N; i++) {
            edges[i] = new ArrayList<>();
        }
        visited = new boolean[N + 1][2];
        dp = new int[N + 1][2];
        for (int i = 1; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            edges[u].add(v);
            edges[v].add(u);
        }
        dfs(1, 0, false);
        dfs(1, 0, true);
        System.out.println(Math.min(dp[1][0], dp[1][1]));
    }
}