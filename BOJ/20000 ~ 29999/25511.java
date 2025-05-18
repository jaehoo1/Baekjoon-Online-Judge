import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    static void dfs(int node, int depth, int findWeight) {

        visited[node] = true;
        if (findWeight == weights[node]) {
            System.out.println(depth);
            System.exit(0);
        }
        for (int i = 0; i < edges[node].size(); i++) {
            int next = edges[node].get(i);
            if (visited[next]) {
                continue;
            }
            dfs(next, depth + 1, findWeight);
        }
    }

    static int[] weights;
    static boolean[] visited;
    static List<Integer>[] edges;

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        weights = new int[n];
        visited = new boolean[n];
        edges = new List[n];
        for (int i = 0; i < n; i++) {
            edges[i] = new ArrayList<>();
        }

        for (int i = 0; i < n - 1; i++) {
            st = new StringTokenizer(br.readLine());
            int p = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            edges[p].add(c);
            edges[c].add(p);
        }

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            weights[i] = Integer.parseInt(st.nextToken());
        }

        dfs(0, 0, k);
    }
}