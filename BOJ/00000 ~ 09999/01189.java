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

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Position position = (Position) o;
        return x == position.x && y == position.y;
    }

    @Override
    public int hashCode() {
        return Objects.hash(x, y);
    }
}

public class Main {

    static int R, C, K, result;
    static char[][] map;
    static int[] nx = {-1, 0, 1, 0,}, ny = {0, 1, 0, -1};
    static Set<Position> visited = new HashSet<>();

    static void dfs(int x, int y, int depth) {
        if (depth == K) {
            if (x == 0 && y == C - 1) {
                result++;
            }
            return;
        }
        for (int i = 0; i < 4; i++) {
            int nextx = x + nx[i];
            int nexty = y + ny[i];
            Position next = new Position(nextx, nexty);
            if (nextx < 0 || nextx >= R || nexty < 0 || nexty >= C || map[nextx][nexty] == 'T' || visited.contains(next)) {
                continue;
            }
            visited.add(next);
            dfs(nextx, nexty, depth + 1);
            visited.remove(next);
        }
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        map = new char[R][C];
        for (int i = 0; i < R; i++) {
            map[i] = br.readLine().toCharArray();
        }
        visited.add(new Position(R - 1, 0));
        dfs(R - 1, 0, 1);
        System.out.println(result);
    }
}
