import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int max = 0, min = Integer.MAX_VALUE;
        while (N-- > 0) {
            int P = Integer.parseInt(br.readLine());
            max = Math.max(max, P);
            min = Math.min(min, P);
        }
        System.out.println(min > max / 2 ? min - max / 2 : 0);
    }
}