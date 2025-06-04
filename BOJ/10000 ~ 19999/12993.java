import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Position {

    long x, y;

    public Position(long x, long y) {
        this.x = x;
        this.y = y;
    }
}

public class Main {

    static boolean bfs(Position dst) {

        Queue<Position> queue = new LinkedList<>();
        queue.add(new Position(0, 0));
        int step = 0;
        while (!queue.isEmpty()) {
            int stepSize = queue.size();
            for (int i = 0; i < stepSize; i++) {
                Position cur = queue.poll();
                if (cur.x == dst.x && cur.y == dst.y) {
                    return true;
                }
                if (cur.x > dst.x || cur.y > dst.y) {
                    continue;
                }
                queue.add(new Position((long) (cur.x + Math.pow(3, step)), cur.y));
                queue.add(new Position(cur.x, (long) (cur.y + Math.pow(3, step))));
            }
            step++;
        }
        return false;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        System.out.println(bfs(new Position(sc.nextInt(), sc.nextInt())) ? 1 : 0);
    }
}