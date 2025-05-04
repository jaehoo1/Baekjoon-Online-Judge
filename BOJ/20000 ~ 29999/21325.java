import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    static List<Integer>[] edges;
    static boolean[] present;
    static int cnt;

    static void dfs(int node) {

        if (present[node]) {
            cnt++;
            return;
        }
        for (int i = 0; i < edges[node].size(); i++) {
            dfs(edges[node].get(i));
        }
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int root = 0;
        edges = new List[N + 1];
        present = new boolean[N + 1];
        for (int i = 1; i <= N; i++) {
            edges[i] = new ArrayList<>();
        }
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            int parent = Integer.parseInt(st.nextToken());
            if (parent == 0) {
                root = i;
                continue;
            }
            edges[parent].add(i);
        }
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < M; i++) {
            present[Integer.parseInt(st.nextToken())] = true;
        }
        dfs(root);
        System.out.println(cnt);
    }
}