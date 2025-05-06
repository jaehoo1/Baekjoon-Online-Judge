import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

class Edge implements Comparable<Edge> {

    int u, v, w;

    public Edge(int u, int v, int w) {
        this.u = u;
        this.v = v;
        this.w = w;
    }

    public Edge(StringTokenizer st) {
        this(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
    }

    @Override
    public int compareTo(Edge o) {
        return this.w - o.w;
    }
}

class UnionFind {

    int[] parent;

    public UnionFind(int nodeCount) {

        parent = new int[nodeCount + 1];
        for (int i = 1; i <= nodeCount; i++) {
            parent[i] = i;
        }
    }

    int findParent(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }

    void unionSet(int a, int b) {
        a = findParent(a);
        b = findParent(b);
        if (a < b) {
            parent[b] = a;
        } else {
            parent[a] = b;
        }
    }
}

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int S = Integer.parseInt(st.nextToken());
        UnionFind unionFind = new UnionFind(N);
        List<Edge> edges = new ArrayList<>();
        for (int i = 0; i < M; i++) {
            edges.add(new Edge(new StringTokenizer(br.readLine())));
        }
        Collections.sort(edges);
        int result = 0;
        for (int i = 0; i < M; i++) {
            Edge edge = edges.get(i);
            if (unionFind.findParent(edge.u) == unionFind.findParent(edge.v)) {
                continue;
            }
            unionFind.unionSet(edge.u, edge.v);
            result += edge.w;
        }
        System.out.println(result);
    }
}