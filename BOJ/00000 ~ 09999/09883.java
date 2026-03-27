import java.util.Scanner;

public class Main {

    static String leadingZero(String s) {
        return "0".repeat(16 - s.length()) + s;
    }

    static String leadingZero(int num) {
        return leadingZero(Integer.toBinaryString(num));
    }

    static long mortonNumber(String x, String y) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < 16; i++) {
            sb.append(x.charAt(i)).append(y.charAt(i));
        }
        return Long.parseLong(sb.toString(), 2);
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        System.out.println(mortonNumber(leadingZero(sc.nextInt()), leadingZero(sc.nextInt())));
    }
}