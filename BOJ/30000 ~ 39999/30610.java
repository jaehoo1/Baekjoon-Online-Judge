import java.util.*;

class Position {

    int x;
    int y;

    public Position(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

public class Main {

    static final int[] nextx = {0, -1,0,1};
    static final int[] nexty = {-1, 0, 1, 0};

    static char[][] tiles;
    static int N;
    static int M;

    private static int bfs(Position position) {

        Queue<Position> queue = new LinkedList<>();
        tiles[position.x][position.y] = '0';
        queue.offer(position);

        int size = 0;
        while (!queue.isEmpty()) {
            size++;
            Position current = queue.poll();
            for (int i = 0; i < 4; i++) {
                int nx = current.x + nextx[i];
                int ny = current.y + nexty[i];
                if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
                    continue;
                }
                if (tiles[nx][ny] == '1') {
                    tiles[nx][ny] = '0';
                    queue.offer(new Position(nx, ny));
                }
            }
        }

        return size;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        sc.nextLine();
        tiles = new char[N][M];
        List<Integer> sizes = new ArrayList<>();

        for (int i = 0; i < N; i++) {
            tiles[i] = sc.nextLine().toCharArray();
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (tiles[i][j] == '1') {
                    sizes.add(bfs(new Position(i, j)));
                }
            }
        }

        sizes.sort(Integer::compareTo);
        System.out.println(sizes.size());
        for (int i = 0; i < sizes.size(); i++) {
            System.out.print(sizes.get(i) + " ");
        }
    }
}