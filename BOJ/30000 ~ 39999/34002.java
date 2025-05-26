import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int A = sc.nextInt();
        int B = sc.nextInt();
        int C = sc.nextInt();
        int S = sc.nextInt();
        int V = sc.nextInt();
        int L = sc.nextInt();
        int min = 0, exp = 0;
        for (; L < 250 && V > 0; V--) {
            for (int i = 0; i < 30; i++, min++, exp += C) {
                if (exp >= 100) {
                    exp -= 100;
                    L++;
                }
                if (L >= 250) {
                    break;
                }
            }
        }
        for (; L < 250 && S > 0; S--) {
            for (int i = 0; i < 30; i++, min++, exp += B) {
                if (exp >= 100) {
                    exp -= 100;
                    L++;
                }
                if (L >= 250) {
                    break;
                }
            }
        }
        for (; L < 250; min++, exp += A) {
            if (exp >= 100) {
                exp -= 100;
                L++;
            }
            if (L >= 250) {
                break;
            }
        }
        System.out.println(min);
    }
}