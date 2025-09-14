import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Objects;
import java.util.StringTokenizer;

class Position {

    int x, y;

    public Position(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public Position(Position position) {
        this(position.x, position.y);
    }

    @Override
    public boolean equals(Object o) {
        Position position = (Position) o;
        return x == position.x && y == position.y;
    }
}

public class Main {

    static final int[] nx = {-1, 0, 1, 0}, ny = {0, 1, 0, -1};
    static char[][] maze;
    static int N, M;

    static int leftTurn(int vec) {
        if (--vec < 0) {
            vec = 3;
        }
        return vec;
    }

    static int rightTurn(int vec) {
        if (++vec >= 4) {
            vec = 0;
        }
        return vec;
    }

    static boolean canMoveForward(int vec, Position cur) {
        int nextx = cur.x + nx[vec];
        int nexty = cur.y + ny[vec];
        if (nextx < 0 || nextx >= N || nexty < 0 || nexty >= M) {
            return false;
        }
        return maze[nextx][nexty] != '*';
    }

    static int leftHand(Position start, Position end) {
        int vec = 0, move = 0;
        for (int i = 0; i < 4; i++) {
            int nextx = start.x + nx[i];
            int nexty = start.y + ny[i];
            if (nextx < 0 || nextx >= N || nexty < 0 || nexty >= M || maze[nextx][nexty] != '.') {
                continue;
            }
            vec = i;
            break;
        }
        Position cur = new Position(start);
        while (!cur.equals(end)) {
            vec = leftTurn(vec);
            while (!canMoveForward(vec, cur)) {
                vec = rightTurn(vec);
            }
            cur.x += nx[vec];
            cur.y += ny[vec];
            move++;
        }
        return move;
    }

    static int rightHand(Position start, Position end) {
        int vec = 0, move = 0;
        for (int i = 0; i < 4; i++) {
            int nextx = start.x + nx[i];
            int nexty = start.y + ny[i];
            if (nextx < 0 || nextx >= N || nexty < 0 || nexty >= M || maze[nextx][nexty] != '.') {
                continue;
            }
            vec = i;
            break;
        }
        Position cur = new Position(start);
        while (!cur.equals(end)) {
            vec = rightTurn(vec);
            while (!canMoveForward(vec, cur)) {
                vec = leftTurn(vec);
            }
            cur.x += nx[vec];
            cur.y += ny[vec];
            move++;
        }
        return move;
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        maze = new char[N][M];
        for (int i = 0; i < N; i++) {
            maze[i] = br.readLine().toCharArray();
        }
        Position start = null, end = null;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (maze[i][j] == 'S') {
                    start = new Position(i, j);
                } else if (maze[i][j] == 'E') {
                    end = new Position(i, j);
                }
            }
        }
        int left = leftHand(start, end);
        int right = rightHand(start, end);
        if (left < right) {
            System.out.println("LEFT IS BEST");
        } else if (left > right) {
            System.out.println("RIGHT IS BEST");
        } else {
            System.out.println("SAME");
        }
    }
}