import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        int max = 0;
        for (int i = 0; i < n; i++) {
            List<Integer> lis = new ArrayList<>();
            lis.add(arr[i]);
            for (int j = i + 1; j < n && lis.get(lis.size() - 1) < arr[j]; j++) {
                lis.add(arr[j]);
            }
            max = Math.max(max, lis.size());
        }
        System.out.println(max);
    }
}