import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        String s = new Scanner(System.in).nextLine();
        System.out.println(s.indexOf("()") + 1 == s.length() / 2 && s.length() % 2 == 0 ? "correct" : "fix");
    }
}