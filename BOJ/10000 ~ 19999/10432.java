import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    static final int N = 12;

    static int[] arr;

    static boolean isIsland(List<Integer> subsequence) {
        if (subsequence.size() < 3) {
            return false;
        }
        for (int i = 1; i < subsequence.size() - 1; i++) {
            if (subsequence.get(0) >= subsequence.get(i)) {
                return false;
            }
        }
        for (int i = 1; i < subsequence.size() - 1; i++) {
            if (subsequence.get(subsequence.size() - 1) >= subsequence.get(i)) {
                return false;
            }
        }
        return true;
    }

    static List<List<Integer>> makeSubsequences() {
        List<List<Integer>> subsequences = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            List<Integer> subsequence = new ArrayList<>();
            for (int j = i; j < N; j++) {
                subsequence.add(arr[j]);
                subsequences.add(List.copyOf(subsequence));
            }
        }
        return subsequences;
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int P = Integer.parseInt(br.readLine());
        while (P-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String T = st.nextToken();
            arr = new int[N];
            for (int i = 0; i < N; i++) {
                arr[i] = Integer.parseInt(st.nextToken());
            }
            bw.write(T + " " + makeSubsequences().stream()
                    .filter(Main::isIsland)
                    .count()
                    + "\n");
        }
        br.close();
        bw.flush();
        bw.close();
    }
}