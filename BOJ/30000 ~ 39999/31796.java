import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        Integer[] arr = new Integer[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(arr, Comparator.reverseOrder());
        int pageCnt = 1, pageMax = arr[0];
        for (int i = 1; i < N; i++) {
            if (arr[i] * 2 <= pageMax) {
                pageCnt++;
                pageMax = arr[i];
            }
        }
        System.out.println(pageCnt);
    }
}