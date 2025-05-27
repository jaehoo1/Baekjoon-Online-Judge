import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int len = Integer.parseInt(br.readLine());
        String log = br.readLine();
        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < len; i++) {
            if (Character.isLowerCase(log.charAt(i))) {
                stack.push(log.charAt(i));
            } else {
                if (stack.isEmpty() || Character.toLowerCase(log.charAt(i)) != stack.peek()) {
                    System.out.println(0);
                    System.exit(0);
                }
                stack.pop();
            }
        }
        System.out.println(stack.isEmpty() ? 1 : 0);
    }
}