import java.math.BigInteger;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {

    static Map<Integer, Integer> primeFactor(int n) {

        Map<Integer, Integer> primes = new HashMap<>();
        int sqrt = (int) Math.sqrt(n) + 1;
        for (int i = 2; i < sqrt; i++) {
            while (n % i == 0) {
                primes.put(i, primes.containsKey(i) ? primes.get(i) + 1 : 1);
                n /= i;
            }
        }
        if (n > 1) {
            primes.put(n, 1);
        }
        return primes;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        Map<Integer, Integer> primes = primeFactor(sc.nextInt());
        BigInteger result = BigInteger.ONE;
        for (int key : primes.keySet()) {
            int value = primes.get(key);
            if (value % 2 == 1) {
                value++;
            }
            result = result.multiply(BigInteger.valueOf(key).pow(value));
        }
        System.out.println(result);
    }
}