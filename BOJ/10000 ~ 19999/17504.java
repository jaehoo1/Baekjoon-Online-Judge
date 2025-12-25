import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Fraction {

    long P, Q;

    public Fraction(long p, long q) {
        P = p;
        Q = q;
    }

    void reverse() {
        long temp = P;
        P = Q;
        Q = temp;
    }
}

public class Main {

    static Fraction plus(int num, Fraction fraction) {
        return new Fraction(fraction.Q * num + fraction.P, fraction.Q);
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int[] arr = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        Fraction fraction = new Fraction(1, arr[N - 1]);
        for (int i = N - 2; i >= 0; i--) {
            fraction = plus(arr[i], fraction);
            fraction.reverse();
        }
        System.out.println(fraction.Q - fraction.P + " " + fraction.Q);
    }
}