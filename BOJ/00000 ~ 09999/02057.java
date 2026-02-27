import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

    static List<Long> factorials = new ArrayList<>();
    static long N;

    static void initFactorials() {

        factorials.add(1L);
        factorials.add(1L);
        for (int i = 2; ; i++) {
            long next = factorials.get(factorials.size() - 1) * i;
            if (next > 1000000000000000000L) {
                break;
            }
            factorials.add(next);
        }
    }

    static void recur(long sum, int depth) {

        if (N == 0) {
            System.out.println("NO");
            System.exit(0);
        }
        if (sum == N) {
            System.out.println("YES");
            System.exit(0);
        }
        if (sum > N || depth == factorials.size()) {
            return;
        }

        recur(sum, depth + 1);
        recur(sum + factorials.get(depth), depth + 1);
    }

    public static void main(String[] args) {

        initFactorials();
        N = new Scanner(System.in).nextLong();
        recur(0, 0);
        System.out.println("NO");
    }
}