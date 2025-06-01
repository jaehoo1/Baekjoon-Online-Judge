import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    static List<Integer>[] edges;
    static long[] dp;
    static int[] weight;
    static boolean[] visited;

    static long dfs(int node) {

        if (visited[node]) {
            return dp[node];
        }
        for (int i = 0; i < edges[node].size(); i++) {
            int next = edges[node].get(i);
            if (dfs(next) <= 0) {
                continue;
            }
            dp[node] += dfs(next);
        }
        dp[node] += weight[node];
        visited[node] = true;
        return dp[node];
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        edges = new List[n];
        dp = new long[n];
        weight = new int[n];
        visited = new boolean[n];
        for (int i = 0; i < n; i++) {
            edges[i] = new ArrayList<>();
        }
        for (int i = 1; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int p = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            edges[p].add(c);
        }
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            weight[i] = Integer.parseInt(st.nextToken());
        }
        System.out.println(dfs(0));
    }
}