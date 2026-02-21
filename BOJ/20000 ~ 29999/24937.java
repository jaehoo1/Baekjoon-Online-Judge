import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        String str = "SciComLove";
        int N = sc.nextInt();
        N %= str.length();
        while (N-- > 0) {
            str = str.substring(1) + str.charAt(0);
        }
        System.out.println(str);
    }
}