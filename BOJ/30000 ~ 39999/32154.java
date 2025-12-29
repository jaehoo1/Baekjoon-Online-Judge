import java.util.Scanner;

public class Main {

    static final String[] SOLVED = {
            "ABCDEFGHJLM",
            "ACEFGHILM",
            "ACEFGHILM",
            "ABCEFGHLM",
            "ACEFGHLM",
            "ACEFGHLM",
            "ACEFGHLM",
            "ACEFGHLM",
            "ACEFGHLM",
            "ABCFGHLM"
    };

    public static void main(String[] args) {

        int N = new Scanner(System.in).nextInt() - 1;
        System.out.println(SOLVED[N].length());
        System.out.println(String.join(" ", SOLVED[N].split("")));
    }
}