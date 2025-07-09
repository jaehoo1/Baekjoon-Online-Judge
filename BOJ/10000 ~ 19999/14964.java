import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Position implements Comparable<Position> {
    int x, y;

    public Position(int x, int y) {
        this.x = x;
        this.y = y;
    }

    Position plusXY(int x, int y) {
        return new Position(this.x + x, this.y + y);
    }

    @Override
    public int compareTo(Position o) {
        if (x == o.x) {
            return y - o.y;
        }
        return x - o.x;
    }

    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Position position = (Position) o;
        return x == position.x && y == position.y;
    }
}

public class Main {

    static char[][] matrix;
    static int[] nx = {-1, 0, 1, 0}, ny = {0, 1, 0, -1};

    static int N, M;

    static int kindsOfFigure(List<Position> positions) {
        if (positions.get(0).plusXY(0, 1).equals(positions.get(1)) &&
                positions.get(0).plusXY(1, 0).equals(positions.get(2)) &&
                positions.get(0).plusXY(1, 1).equals(positions.get(3))) {
            return 0;
        }
        if (positions.get(0).plusXY(0, 1).equals(positions.get(1)) &&
                positions.get(0).plusXY(0, 2).equals(positions.get(2)) &&
                positions.get(0).plusXY(0, 3).equals(positions.get(3))) {
            return 1;
        }
        if (positions.get(0).plusXY(1, 0).equals(positions.get(1)) &&
                positions.get(0).plusXY(2, 0).equals(positions.get(2)) &&
                positions.get(0).plusXY(3, 0).equals(positions.get(3))) {
            return 1;
        }
        if (positions.get(0).plusXY(0, 1).equals(positions.get(1)) &&
                positions.get(0).plusXY(1, -1).equals(positions.get(2)) &&
                positions.get(0).plusXY(1, 0).equals(positions.get(3))) {
            return 2;
        }
        if (positions.get(0).plusXY(1, 0).equals(positions.get(1)) &&
                positions.get(0).plusXY(1, 1).equals(positions.get(2)) &&
                positions.get(0).plusXY(2, 1).equals(positions.get(3))) {
            return 2;
        }
        if (positions.get(0).plusXY(0, 1).equals(positions.get(1)) &&
                positions.get(0).plusXY(1, 1).equals(positions.get(2)) &&
                positions.get(0).plusXY(1, 2).equals(positions.get(3))) {
            return 3;
        }
        if (positions.get(0).plusXY(1, -1).equals(positions.get(1)) &&
                positions.get(0).plusXY(1, 0).equals(positions.get(2)) &&
                positions.get(0).plusXY(2, -1).equals(positions.get(3))) {
            return 3;
        }
        return 4;
    }

    static List<Position> figurePositions(Position p) {
        Queue<Position> queue = new LinkedList<>();
        List<Position> positions = new ArrayList<>();
        char c = matrix[p.x][p.y];
        queue.add(new Position(p.x, p.y));
        positions.add(new Position(p.x, p.y));
        matrix[p.x][p.y] = '.';
        while (!queue.isEmpty()) {
            Position cur = queue.poll();
            for (int i = 0; i < 4; i++) {
                int nextx = cur.x + nx[i];
                int nexty = cur.y + ny[i];
                if (nextx < 0 || nextx >= N || nexty < 0 || nexty >= M || matrix[nextx][nexty] == '.' || matrix[nextx][nexty] != c) {
                    continue;
                }
                queue.add(new Position(nextx, nexty));
                positions.add(new Position(nextx, nexty));
                matrix[nextx][nexty] = '.';
            }
        }
        return positions;
    }

    public static void main(String[] args) throws IOException {

        int[] figures = new int[5];

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        matrix = new char[N][M];
        for (int i = 0; i < N; i++) {
            matrix[i] = br.readLine().toCharArray();
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (matrix[i][j] != '.') {
                    List<Position> positions = figurePositions(new Position(i, j));
                    positions.sort(Position::compareTo);
                    figures[kindsOfFigure(positions)]++;
                }
            }
        }

        Arrays.stream(figures).forEach(System.out::println);
    }
}