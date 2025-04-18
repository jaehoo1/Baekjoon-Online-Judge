import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int n, T;
        long num;
        n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            T = sc.nextInt();
            Map<Long, Integer> map = new HashMap<>();
            for (int j = 0; j < T; j++) {
                num = sc.nextLong();
                if (map.get(num) == null) {
                    map.put(num, 1);
                } else {
                    map.put(num, map.get(num) + 1);
                }
            }
            int maxCnt = 0;
            long maxNum = 0;
            for (Map.Entry<Long, Integer> entry : map.entrySet()) {
                if (entry.getValue() > maxCnt) {
                    maxCnt = entry.getValue();
                    maxNum = entry.getKey();
                }
            }
            System.out.println(maxCnt > T / 2 ? maxNum : "SYJKGW");
        }
    }
}