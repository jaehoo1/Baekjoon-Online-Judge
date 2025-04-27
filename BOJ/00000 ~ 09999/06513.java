import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {

    static final String VOWEL = "aeiou";
    static Map<String, String> irregularWords = new HashMap<>();

    static String plural(String s) {

        char last = s.charAt(s.length() - 1);
        char secondLast = s.charAt(s.length() - 2);
        if (irregularWords.containsKey(s)) {
            return irregularWords.get(s);
        } else if (last == 'y' && VOWEL.indexOf(secondLast) == -1) {
            return s.substring(0, s.length() - 1) + "ies";
        } else if (last == 'o' || last == 's' || (last == 'h' && (secondLast == 'c' || secondLast == 's')) || last == 'x') {
            return s + "es";
        } else {
            return s + "s";
        }
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int L = sc.nextInt();
        int N = sc.nextInt();
        for (int i = 0; i < L; i++) {
            irregularWords.put(sc.next(), sc.next());
        }
        for (int i = 0; i < N; i++) {
            System.out.println(plural(sc.next()));
        }
    }
}