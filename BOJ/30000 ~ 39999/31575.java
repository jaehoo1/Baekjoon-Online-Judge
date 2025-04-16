import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Position {

    int x, y;

    public Position(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

public class Main {

    static boolean[][] visited = new boolean[300][300];
    static int[][] arr = new int[300][300];
    static int N, M;

    static boolean bfs() {

        int[] nx = {0, 1};
        int[] ny = {1, 0};
        Queue<Position> queue = new LinkedList<>();
        queue.add(new Position(0, 0));
        visited[0][0] = true;
        while (!queue.isEmpty()) {
            Position cur = queue.remove();
            if (cur.x == M - 1 && cur.y == N - 1) {
                return true;
            }
            for (int i = 0; i < 2; i++) {
                Position next = new Position(cur.x + nx[i], cur.y + ny[i]);
                if (next.x >= M || next.y >= N) {
                    continue;
                }
                if (arr[next.x][next.y] == 1 && !visited[next.x][next.y]) {
                    queue.add(next);
                    visited[next.x][next.y] = true;
                }
            }
        }
        return false;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                arr[i][j] = sc.nextInt();
            }
        }
        System.out.println(bfs() ? "Yes" : "No");
    }
}