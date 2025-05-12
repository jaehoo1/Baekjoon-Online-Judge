import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    static int[] dp;
    static List<Integer>[] edges;

    static void dfs(int node, int praise) {
        dp[node] += praise;
        for (int next : edges[node]) {
            dfs(next, dp[node]);
        }
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        dp = new int[n + 1];
        edges = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) {
            edges[i] = new ArrayList<>();
        }
        int m = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; i++) {
            int parent = Integer.parseInt(st.nextToken());
            if (i == 1) {
                continue;
            }
            edges[parent].add(i);
        }
        while (m-- > 0) {
            st = new StringTokenizer(br.readLine());
            int i = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());
            dp[i] += w;
        }
        dfs(1, 0);
        for (int i = 1; i <= n; i++) {
            bw.write(dp[i] + " ");
        }
        br.close();
        bw.flush();
        bw.close();
    }
}