import java.util.*;

class Position {

    int x, y;

    public Position(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

class Mineral extends Position {

    public Mineral(int x, int y) {
        super(x, y);
    }
}

class Cluster {
    
    List<Mineral> minerals;

    public Cluster(Mineral mineral) {

        minerals = new ArrayList<>();
        Queue<Position> queue = new LinkedList<>();
        boolean[][] visited = new boolean[Main.R][Main.C];

        minerals.add(mineral);
        queue.add(new Position(mineral.x, mineral.y));
        visited[mineral.x][mineral.y] = true;
        while (!queue.isEmpty()) {
            Position cur = queue.poll();
            for (int i = 0; i < 4; i++) {
                int nextx = cur.x + Main.nx[i];
                int nexty = cur.y + Main.ny[i];
                if (nextx < 0 || nextx >= Main.R || nexty < 0 || nexty >= Main.C || Main.cave[nextx][nexty] == '.' || visited[nextx][nexty]) {
                    continue;
                }
                minerals.add(new Mineral(nextx, nexty));
                queue.add(new Position(nextx, nexty));
                visited[nextx][nexty] = true;
            }
        }
    }

    List<Mineral> getFloorMinerals() {

        boolean[] columns = new boolean[Main.C];
        int[] floors = new int[Main.C];

        for (Mineral mineral : minerals) {
            columns[mineral.y] = true;
            if (mineral.x > floors[mineral.y]) {
                floors[mineral.y] = mineral.x;
            }
        }

        List<Mineral> floorMinerals = new ArrayList<>();
        for (int i = 0; i < Main.C; i++) {
            if (columns[i]) {
                floorMinerals.add(new Mineral(floors[i], i));
            }
        }
        return floorMinerals;
    }

    boolean isFalling() {

        List<Mineral> floorMinerals = getFloorMinerals();
        for (Mineral mineral : floorMinerals) {
            for (int i = 0; i < 4; i++) {
                int nextx = mineral.x + Main.nx[i];
                if (nextx == Main.R) {
                    return false;
                }
            }
        }
        return true;
    }

    int getFallingHeight() {

        List<Mineral> floorMinerals = getFloorMinerals();
        int fallingHeight = 1;
        while (true) {
            for (Mineral mineral : floorMinerals) {
                int nextx = mineral.x + fallingHeight;
                if (nextx == Main.R || Main.cave[nextx][mineral.y] == 'x') {
                    return fallingHeight - 1;
                }
            }
            fallingHeight++;
        }
    }

    void fall() {

        Queue<Mineral> delQueue = new LinkedList<>(minerals);
        Queue<Mineral> addQueue = new LinkedList<>();
        int fallingHeight = getFallingHeight();
        while (!delQueue.isEmpty()) {
            Mineral moving = delQueue.poll();
            Main.cave[moving.x][moving.y] = '.';
            addQueue.add(new Mineral(moving.x + fallingHeight, moving.y));
        }
        while (!addQueue.isEmpty()) {
            Mineral moved = addQueue.poll();
            Main.cave[moved.x][moved.y] = 'x';
        }
    }
}

public class Main {

    static int R, C;
    static char[][] cave;
    static int[] nx = {-1, 0, 1, 0}, ny = {0, 1, 0, -1};

    static Position findTarget(int height, boolean startLeft) {

        height = R - height;
        for (int i = startLeft ? 0 : C - 1; i >= 0 && i < C; i += (startLeft ? 1 : -1)) {
            if (cave[height][i] == 'x') {
                return new Position(height, i);
            }
        }
        return null;
    }

    static Cluster findFallingCluster(Position destroyed) {

        char[][] copiedCave = new char[R][C];
        for (int i = 0; i < R; i++) {
            System.arraycopy(cave[i], 0, copiedCave[i], 0, C);
        }

        for (int i = 0; i < 4; i++) {
            int nextx = destroyed.x + nx[i];
            int nexty = destroyed.y + ny[i];
            if (nextx < 0 || nextx >= R || nexty < 0 || nexty >= C || copiedCave[nextx][nexty] != 'x') {
                continue;
            }
            Cluster cluster = new Cluster(new Mineral(nextx, nexty));
            if (cluster.isFalling()) {
                return cluster;
            }
        }
        return null;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        R = sc.nextInt();
        C = sc.nextInt();
        sc.nextLine();
        cave = new char[R][C];
        for (int i = 0; i < R; i++) {
            cave[i] = sc.nextLine().toCharArray();
        }
        int N = sc.nextInt();
        for (int i = 0; i < N; i++) {
            Position target = findTarget(sc.nextInt(), i % 2 == 0);
            if (target == null) {
                continue;
            }
            cave[target.x][target.y] = '.';
            Cluster fallingCluster = findFallingCluster(target);
            if (fallingCluster == null) {
                continue;
            }
            fallingCluster.fall();
        }
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                System.out.print(cave[i][j]);
            }
            System.out.println();
        }
    }
}