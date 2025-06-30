import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        String S = sc.next();
        int result;
        if (S.equals("(1)")) {
            result = 0;
        } else if (S.contains("(1") || S.contains("1)") || S.contains("()")) {
            result = 1;
        } else {
            result = 2;
        }
        System.out.println(result);
    }
}