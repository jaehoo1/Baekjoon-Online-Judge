import java.util.Scanner;
import java.util.stream.IntStream;

public class Main {

    static int[] team = new int[4];
    static int[] skills = new int[8];
    static int min;

    static void recur(int idx, int depth) {
        team[depth] = idx;
        if (depth == 3) {
            int diff = 0;
            for (int i = 0; i < 8; i++) {
                int finding = i;
                if (IntStream.of(team).anyMatch(t -> t == finding)) {
                    diff += skills[i];
                } else {
                    diff -= skills[i];
                }
            }
            if (Math.abs(diff) < min) {
                min = Math.abs(diff);
            }
            return;
        }
        for (int i = idx + 1; i < 8; i++) {
            recur(i, depth + 1);
        }
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int T, N;
        T = sc.nextInt();
        for (int t = 0; t < T; t++) {
            min = Integer.MAX_VALUE;
            N = sc.nextInt();
            for (int i = 0; i < N; i++) {
                skills[i] = sc.nextInt();
            }
            for (int i = 0; i < N; i++) {
                recur(i, 0);
            }
            System.out.println("Case #" + (t + 1) + ": " + min);
        }
    }
}