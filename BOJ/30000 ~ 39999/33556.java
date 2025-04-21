import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        String A = sc.next();
        String B = sc.next();
        if (A.equals("null")) {
            System.out.println("NullPointerException");
            System.out.println("NullPointerException");
        } else if (B.equals("null")) {
            System.out.println("false");
            System.out.println("false");
        } else {
            System.out.println(A.equals(B));
            System.out.println(A.equalsIgnoreCase(B));
        }
    }
}