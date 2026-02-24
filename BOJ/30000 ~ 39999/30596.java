import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    static int[] a = new int[4];
    static boolean[] visited = new boolean[4];

    static int max;

    static int area(int[] sticks) {
        return Math.min(sticks[0], sticks[1]) * Math.min(sticks[2], sticks[3]);
    }

    static void dfs(int[] tree, int depth) {
        if (depth == 4) {
            max = Math.max(max, area(tree));
            return;
        }
        for (int i = 0; i < 4; i++) {
            if (visited[i]) {
                continue;
            }
            visited[i] = true;
            tree[depth] = a[i];
            dfs(tree, depth + 1);
            visited[i] = false;
        }
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        for (int i = 0; i < 4; i++) {
            a[i] = Integer.parseInt(br.readLine());
        }
        dfs(new int[4], 0);
        System.out.println(max);
    }
}