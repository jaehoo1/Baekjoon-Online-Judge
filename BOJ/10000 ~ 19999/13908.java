import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    static int n, m;
    static List<Integer> included;

    static boolean isValidPassword(int password) {
        int bitmask = 0;
        for (int i = 0; i < n; i++) {
            int pow = (int) Math.pow(10, n - i - 1);
            int div = password / pow;
            password %= pow;
            for (int j = 0; j < m; j++) {
                if (included.get(j) == div) {
                    bitmask |= 1 << j;
                }
            }
        }
        return bitmask == (1 << m) - 1;
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        if (m > 0) {
            included = new ArrayList<>(m);
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < m; i++) {
                included.add(Integer.valueOf(st.nextToken()));
            }
        }
        int maxNum = Integer.parseInt(1 + "0".repeat(n));
        int validPassword = 0;
        for (int i = 0; i < maxNum; i++) {
            if (isValidPassword(i)) {
                validPassword++;
            }
        }
        System.out.println(validPassword);
    }
}