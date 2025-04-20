import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        String yonsei = "YONSEI", korea = "KOREA";
        int y = 0, k = 0, i = 0;
        String S = sc.next();
        while (true) {
            char c = S.charAt(i);
            if (c == yonsei.charAt(y)) {
                y++;
            }
            if (y == 6) {
                System.out.println("YONSEI");
                System.exit(0);
            }
            if (c == korea.charAt(k)) {
                k++;
            }
            if (k == 5) {
                System.out.println("KOREA");
                System.exit(0);
            }
            i++;
        }
    }
}