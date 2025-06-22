import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class UnionFind {

    int[] parent;

    public UnionFind(int size) {
        parent = new int[size + 1];
        for (int i = 1; i <= size; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (x == parent[x]) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    void unionSet(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) {
            return;
        }
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
        int[] cities = new int[N + 1];
        UnionFind unionFind = new UnionFind(N);
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            cities[i] = Integer.parseInt(st.nextToken());
        }
        while (M-- > 0) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            unionFind.unionSet(u, v);
        }
        Map<Integer, Integer> minCosts = new HashMap<>();
        for (int i = 1; i <= N; i++) {
            int treeRoot = unionFind.find(i);
            minCosts.put(treeRoot, Math.min(cities[i], minCosts.getOrDefault(treeRoot, Integer.MAX_VALUE)));
        }
        int minRoot = 0;
        int minCost = Integer.MAX_VALUE;
        for (Map.Entry<Integer, Integer> entry : minCosts.entrySet()) {
            if (entry.getValue() < minCost) {
                minRoot = entry.getKey();
                minCost = entry.getValue();
            }
        }
        int cost = 0;
        for (Map.Entry<Integer, Integer> entry : minCosts.entrySet()) {
            if (entry.getKey() == minRoot) {
                continue;
            }
            cost += minCost * entry.getValue();
        }
        System.out.println(cost);
    }
}