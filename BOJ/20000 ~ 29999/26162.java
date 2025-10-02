import java.io.*;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class Main {

    static boolean isPrime(int n) {

        if (n == 1) {
            return false;
        }
        for (int i = 2; i < n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    static List<int[]> sumByTwoInteger(int n) {

        return IntStream.range(1, n)
                .mapToObj(i -> new int[]{n - i, i})
                .collect(Collectors.toList());
    }

    static boolean isSynthesizable(int n) {

        return sumByTwoInteger(n).stream()
                .anyMatch(arr -> isPrime(arr[0]) && isPrime(arr[1]));
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        while (N-- > 0) {
            bw.write(isSynthesizable(Integer.parseInt(br.readLine())) ? "Yes\n" : "No\n");
        }
        br.close();
        bw.flush();
        bw.close();
    }
}