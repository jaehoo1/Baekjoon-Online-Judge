import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {

    static int N;

    static long bfs() {
        Queue<String> queue = new LinkedList<>();
        queue.add("1");
        while (!queue.isEmpty()) {
            long l = Long.parseLong(queue.poll());
            if (l % N == 0) {
                return l;
            }
            queue.add(l + "0");
            queue.add(l + "1");
        }
        return 0;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int T;
        T = sc.nextInt();
        for (int i = 0; i < T; i++) {
            N = sc.nextInt();
            System.out.println(bfs());
        }
    }
}