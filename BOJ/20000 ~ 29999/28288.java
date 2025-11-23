import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int max = 0;
        char[][] attendances = new char[N][5];
        List<String> result = new ArrayList<>(5);
        for (int i = 0; i < N; i++) {
            attendances[i] = br.readLine().toCharArray();
        }
        for (int i = 0; i < 5; i++) {
            int cnt = 0;
            for (int j = 0; j < N; j++) {
                if (attendances[j][i] == 'Y') {
                    cnt++;
                }
            }
            max = Math.max(max, cnt);
        }
        for (int i = 0; i < 5; i++) {
            int cnt = 0;
            for (int j = 0; j < N; j++) {
                if (attendances[j][i] == 'Y') {
                    cnt++;
                }
            }
            if (cnt == max) {
                result.add(String.valueOf(i + 1));
            }
        }
        System.out.println(String.join(",", result));
    }
}