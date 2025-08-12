import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[] hats = new int[N];
        int result = 0;
        for (int i = 0; i < N; i++) {
            hats[i] = Integer.parseInt(br.readLine());
        }
        for (int i = 0; i < N / 2; i++) {
            if (hats[i] == hats[i + N / 2]) {
                result++;
            }
        }
        System.out.println(result * 2);
    }
}