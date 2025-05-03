import java.io.*;
import java.util.*;

public class Main {

    static List<Integer>[] edges;
    static boolean[] visited;
    static int[] parent;

    static void bfs(int root) {

        Queue<Integer> queue = new LinkedList<>();
        parent[root] = -1;
        visited[root] = true;
        queue.add(root);
        while (!queue.isEmpty()) {
            int cur = queue.poll();
            for (int i = 0; i < edges[cur].size(); i++) {
                int nextNode = edges[cur].get(i);
                if (visited[nextNode]) {
                    continue;
                }
                parent[nextNode] = cur;
                visited[nextNode] = true;
                queue.add(nextNode);
            }
        }
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        int[] arr = new int[N];
        int maxNodeNum = 0;
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
            if (arr[i] > maxNodeNum) {
                maxNodeNum = arr[i];
            }
        }
        edges = new List[maxNodeNum + 1];
        visited = new boolean[maxNodeNum + 1];
        parent = new int[maxNodeNum + 1];
        for (int i = 0; i < edges.length; i++) {
            edges[i] = new ArrayList<>();
        }
        for (int i = 1; i < N; i++) {
            int src = arr[i - 1];
            int dst = arr[i];
            edges[src].add(dst);
        }
        bfs(arr[0]);
        bw.write(parent.length + "\n");
        for (int i = 0; i < parent.length; i++) {
            bw.write(parent[i] + " ");
        }
        br.close();
        bw.flush();
        bw.close();
    }
}