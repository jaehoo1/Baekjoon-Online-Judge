import java.io.*;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        Deque<Integer> deque = new ArrayDeque<>();
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int cmd = Integer.parseInt(st.nextToken());

            if (cmd == 1) {
                int X = Integer.parseInt(st.nextToken());
                deque.addFirst(X);
            } else if (cmd == 2) {
                int X = Integer.parseInt(st.nextToken());
                deque.addLast(X);
            } else if (cmd == 3) {
                bw.write((deque.isEmpty() ? -1 : deque.removeFirst()) + "\n");
            } else if (cmd == 4) {
                bw.write((deque.isEmpty() ? -1 : deque.removeLast()) + "\n");
            } else if (cmd == 5) {
                bw.write(deque.size() + "\n");
            } else if (cmd == 6) {
                bw.write((deque.isEmpty() ? 1 : 0) + "\n");
            } else if (cmd == 7) {
                bw.write((deque.isEmpty() ? -1 : deque.getFirst()) + "\n");
            } else if (cmd == 8) {
                bw.write((deque.isEmpty() ? -1 : deque.getLast()) + "\n");
            }
        }

        bw.flush();
        br.close();
        bw.close();
    }
}