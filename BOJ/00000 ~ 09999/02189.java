import java.io.*;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {

    static int[][] square;
    static int n;

    static boolean isConsecutive() {
        int[] arr = new int[n * n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                arr[i * n + j] = square[i][j];
            }
        }
        Arrays.sort(arr);
        for (int i = 1; i < arr.length; i++) {
            if (arr[i - 1] + 1 != arr[i]) {
                return false;
            }
        }
        return true;
    }

    static boolean isDistinct() {
        Set<Integer> set = new HashSet<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                set.add(square[i][j]);
            }
        }
        return set.size() == n * n;
    }

    static int[] rowSums() {
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                arr[i] += square[i][j];
            }
        }
        return arr;
    }

    static int[] columnSums() {
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                arr[i] += square[j][i];
            }
        }
        return arr;
    }

    static int[] diagonalSums() {
        int[] arr = new int[2];
        for (int i = 0; i < n; i++) {
            arr[0] += square[i][i];
            arr[1] += square[i][n - 1 - i];
        }
        return arr;
    }

    static boolean isSameSums(int[] sums1, int[] sums2) {
        Set<Integer> set = new HashSet<>();
        for (int i : sums1) {
            set.add(i);
        }
        for (int i : sums2) {
            set.add(i);
        }
        return set.size() == 1;
    }

    static String kindsOfSquare() {
        int[] rowSums = rowSums();
        int[] columnSums = columnSums();
        int[] diagonalSums = diagonalSums();
        if (isSameSums(rowSums, columnSums)) {
            if (isSameSums(rowSums, diagonalSums)) {
                if (isDistinct()) {
                    if (isConsecutive()) {
                        return "Magically-Magick Square";
                    }
                    return "Strongly-Magick Square";
                }
                return "Weakly-Magick Square";
            }
            return "Semi-Magick Square";
        }
        return "Not a Magick Square";
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        for (int t = 1; ; t++) {
            n = Integer.parseInt(br.readLine());
            if (n == 0) {
                break;
            }
            square = new int[n][n];
            for (int i = 0; i < n; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                for (int j = 0; j < n; j++) {
                    square[i][j] = Integer.parseInt(st.nextToken());
                }
            }
            bw.write("Square " + t + ": " + kindsOfSquare() + "\n");
        }
        br.close();
        bw.flush();
        bw.close();
    }
}