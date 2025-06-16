import java.util.Scanner;

public class Main {

    static final String KOREA = "KOREA";

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        String S = sc.nextLine();
        int idx = 0, len = 0;

        for (int i = 0; i < S.length(); i++) {
            if (S.charAt(i) == KOREA.charAt(idx)) {
                idx++;
                len++;
                if (idx == KOREA.length()) {
                    idx = 0;
                }
            }
        }
        System.out.println(len);
    }
}