import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        String w = new Scanner(System.in).next();
        int iFree = 0;
        for (int i = 0; i < 26; i++) {
            StringBuilder sb = new StringBuilder();
            for (int j = 0; j < w.length(); j++) {
                char c = w.charAt(j);
                c += i;
                if (c > 'z') {
                    c -= 26;
                }
                sb.append(c);
            }
            iFree += sb.toString().contains("i") ? 0 : 1;
        }
        System.out.println(iFree == 0 ? "impossible" : iFree);
    }
}