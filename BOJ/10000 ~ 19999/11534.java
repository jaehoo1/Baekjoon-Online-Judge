import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        String first = sc.next();
        String second = sc.next();
        List<Character> chars = new ArrayList<>();
        for (int i = 0; i < first.length(); i++) {
            chars.add(first.charAt(i));
        }
        for (int i = 0; i < second.length() && !chars.isEmpty(); i++) {
            char c = second.charAt(i);
            if (c == chars.get(0)) {
                chars.remove(0);
                continue;
            }
            for (int j = 1; j < chars.size(); j++) {
                if (c == chars.get(j)) {
                    System.out.println("FAIL");
                    System.exit(0);
                }
            }
        }
        System.out.println(chars.isEmpty() ? "PASS" : "FAIL");
    }
}