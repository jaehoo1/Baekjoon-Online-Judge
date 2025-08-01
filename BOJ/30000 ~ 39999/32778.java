import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        String s = new Scanner(System.in).nextLine();
        String mainName, subName;
        if (s.contains("(")) {
            mainName = s.substring(0, s.indexOf("(") - 1);
            subName = s.substring(s.indexOf("(") + 1, s.length() - 1);
        } else {
            mainName = s;
            subName = "-";
        }
        System.out.println(mainName);
        System.out.println(subName);
    }
}