import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[] A = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }
        while (A.length > 1) {
            int[] arr = new int[A.length - 1];
            for (int i = 0; i < arr.length; i++) {
                arr[i] = Math.abs(A[i] - A[i + 1]);
            }
            A = arr;
        }
        System.out.println(A[0]);
    }
}