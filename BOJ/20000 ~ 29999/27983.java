import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int[] X;
    static int[] L;
    static char[] C;

    static int distance(int i, int j) {
        return Math.abs(X[i] - X[j]);
    }

    static int length(int i, int j) {
        return L[i] + L[j];
    }

    static boolean isBeautiful(int i, int j) {
        return distance(i, j) <= length(i, j) && C[i] != C[j];
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        X = new int[N];
        L = new int[N];
        C = new char[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            X[i] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            L[i] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            C[i] = st.nextToken().charAt(0);
        }
        for (int i = 0; i < N - 1; i++) {
            for (int j = i + 1; j < N; j++) {
                if (isBeautiful(i, j)) {
                    System.out.println("YES");
                    System.out.println((i + 1) + " " + (j + 1));
                    System.exit(0);
                }
            }
        }
        System.out.println("NO");
    }
}