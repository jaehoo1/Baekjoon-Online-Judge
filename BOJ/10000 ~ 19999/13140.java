import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        for (int d = 0; d < 10; d++) {
            for (int e = 0; e < 10; e++) {
                if (e == d) {
                    continue;
                }
                for (int h = 1; h < 10; h++) {
                    if (h == d || h == e) {
                        continue;
                    }
                    for (int l = 0; l < 10; l++) {
                        if (l == d || l == e || l == h) {
                            continue;
                        }
                        for (int o = 0; o < 10; o++) {
                            if (o == d || o == e || o == h || o == l) {
                                continue;
                            }
                            for (int r = 0; r < 10; r++) {
                                if (r == d || r == e || r == h || r == l || r == o) {
                                    continue;
                                }
                                for (int w = 1; w < 10; w++) {
                                    if (w == d || w == e || w == h || w == l || w == o || w == r) {
                                        continue;
                                    }
                                    if (h * 10000 + e * 1000 + l * 100 + l * 10 + o + w * 10000 + o * 1000 + r * 100 + l * 10 + d == N) {
                                        System.out.println("  " + h + e + l + l + o);
                                        System.out.println("+ " + w + o + r + l + d);
                                        System.out.println("-------");
                                        System.out.printf("%7d", N);
                                        return;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        System.out.println("No Answer");
    }
}