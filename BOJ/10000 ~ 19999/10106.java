import java.io.*;
import java.util.Stack;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            int N = Integer.parseInt(br.readLine());
            Stack<Integer> mountain = new Stack<>();
            Stack<Integer> branch = new Stack<>();
            for (int i = 0; i < N; i++) {
                mountain.push(Integer.valueOf(br.readLine()));
            }
            int lake = 1;
            while (!mountain.isEmpty()) {
                if (lake == mountain.peek()) {
                    mountain.pop();
                    lake++;
                } else if (!branch.isEmpty() && branch.peek() == lake) {
                    branch.pop();
                    lake++;
                } else {
                    branch.push(mountain.pop());
                }
            }
            while (!branch.isEmpty()) {
                if (lake == branch.pop()) {
                    lake++;
                }
            }
            bw.write((lake == N + 1 ? "Y" : "N") + "\n");
        }
        br.close();
        bw.flush();
        bw.close();
    }
}