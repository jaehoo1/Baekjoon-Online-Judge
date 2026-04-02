import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int[] T = new int[N];
        for (int i = 0; i < N; i++) {
            T[i] = Integer.parseInt(br.readLine());
        }
        int count = 0;
        int time = 30;
        for (int i = 0; i < N; i++) {
            if (time >= T[i]) {
                time -= T[i];
                count++;
            } else if (time >= (double) T[i] / 2) {
                time = 0;
                count++;
            } else {
                time = 0;
            }
            if (time == 0) {
                time = 30;
            }
        }
        System.out.println(count);
    }
}