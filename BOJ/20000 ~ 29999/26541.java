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

    static final int[] nx = {-1, 0, 1, 0};
    static final int[] ny = {0, 1, 0, -1};

    static boolean bfs(char[][] field, String tools) {

        int s = field.length;
        boolean[][] visited = new boolean[s][s];
        Queue<Position> queue = new LinkedList<>();
        for (int i = 0; i < s; i++) {
            for (int j = 0; j < s; j++) {
                if (field[i][j] == 'S') {
                    queue.add(new Position(i, j));
                    visited[i][j] = true;
                }
            }
        }
        while (!queue.isEmpty()) {
            Position cur = queue.poll();
            if (field[cur.x][cur.y] == 'X') {
                return true;
            }
            int nextx;
            int nexty;
            for (int i = 0; i < 4; i++) {
                nextx = cur.x + nx[i];
                nexty = cur.y + ny[i];
                if (nextx < 0 || nextx >= s || nexty < 0 || nexty >= s || visited[nextx][nexty]) {
                    continue;
                }
                if (field[nextx][nexty] != 'X' && field[nextx][nexty] != '.' && tools.indexOf(field[nextx][nexty]) == -1) {
                    continue;
                }
                queue.add(new Position(nextx, nexty));
                visited[nextx][nexty] = true;
            }
        }
        return false;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        String[] cases = {"", "R", "B", "G", "RB", "BG", "RG", "RBG"};

        int n = sc.nextInt();
        while (n-- > 0) {
            int s = sc.nextInt();
            sc.nextLine();
            char[][] field = new char[s][s];
            for (int i = 0; i < s; i++) {
                field[i] = sc.nextLine().toCharArray();
            }
            for (String c : cases) {
                if (bfs(field, c)) {
                    System.out.println(c.length());
                    break;
                }
            }
        }
    }
}