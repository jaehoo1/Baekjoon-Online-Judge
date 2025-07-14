import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Position {

    int x, y;

    public Position(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

public class Main {

    static int R, C;
    static char[][] grid;

    static int bfs(int x, int y) {

        int result = 0;
        Queue<Position> queue = new LinkedList<>();
        queue.add(new Position(x, y));
        while (!queue.isEmpty()) {
            Position cur = queue.poll();
            if (cur.x == R - 1 && cur.y == C - 1) {
                result++;
                continue;
            }
            queue.addAll(nextPositions(cur));
        }
        return result;
    }

    static List<Position> nextPositions(Position cur) {

        List<Position> positions = new ArrayList<>();
        for (int i = cur.x + 1; i < R; i++) {
            for (int j = cur.y + 1; j < C; j++) {
                if (grid[cur.x][cur.y] != grid[i][j]) {
                    positions.add(new Position(i, j));
                }
            }
        }
        return positions;
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        grid = new char[R][C];
        for (int i = 0; i < R; i++) {
            grid[i] = br.readLine().toCharArray();
        }
        System.out.println(bfs(0, 0));
    }
}