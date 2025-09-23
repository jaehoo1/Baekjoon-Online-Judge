import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int T = Integer.parseInt(st.nextToken());
        int D = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        Queue<Integer> queue = new LinkedList<>();
        while (M-- > 0) {
            queue.offer(Integer.valueOf(br.readLine()));
        }
        int sleep = 0;
        boolean properlyRested = false;
        for (int time = 1; time <= D; time++) {
            sleep++;
            if (sleep >= T) {
                properlyRested = true;
            }
            if (!queue.isEmpty() && queue.peek() == time) {
                queue.poll();
                sleep = 0;
            }
        }
        if (sleep >= T) {
            properlyRested = true;
        }
        System.out.println(properlyRested ? 'Y' : 'N');
    }
}