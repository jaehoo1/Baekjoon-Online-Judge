import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int sum = 0;
        int N = Integer.parseInt(br.readLine());
        int cur = Integer.parseInt(br.readLine());
        while (N-- > 0) {
            int next = Integer.parseInt(br.readLine());
            sum += Math.min(Math.abs(next - cur), Math.abs(360 - Math.abs(next - cur)));
            cur = next;
        }
        System.out.println(sum);
    }
}