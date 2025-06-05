import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        Integer[] C = new Integer[N];
        for (int i = 0; i < N; i++) {
            C[i] = Integer.parseInt(br.readLine());
        }
        Arrays.sort(C, Comparator.reverseOrder());
        int cost = 0;
        for (int i = 0; i < N; i++) {
            if (i % 3 == 2) {
                continue;
            }
            cost += C[i];
        }
        System.out.println(cost);
    }
}