import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int C = Integer.parseInt(br.readLine());
        int max = 100;
        int cur = 100;
        while (C-- > 0) {
            cur += Integer.parseInt(br.readLine());
            max = Math.max(max, cur);
        }
        System.out.println(max);
    }
}