import java.io.*;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        Stack<Integer> stack = new Stack<>();
        int N, X;
        String line;

        N = Integer.parseInt(br.readLine());
        for (int i = 0; i < N; i++) {
            line = br.readLine();
            char cmd = line.charAt(0);
            if (cmd == '1') {
                StringTokenizer st = new StringTokenizer(line);
                st.nextToken();
                X = Integer.parseInt(st.nextToken());
                stack.push(X);
            } else if (cmd == '2') {
                bw.write((stack.isEmpty() ? -1 : stack.pop()) + "\n");
            } else if (cmd == '3') {
                bw.write(stack.size() + "\n");
            } else if (cmd == '4') {
                bw.write((stack.isEmpty() ? 1 : 0) + "\n");
            } else if (cmd == '5') {
                bw.write((stack.isEmpty() ? -1 : stack.peek()) + "\n");
            }
        }

        bw.flush();
        br.close();
        bw.close();
    }
}