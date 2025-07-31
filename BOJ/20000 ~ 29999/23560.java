import java.util.Scanner;

public class Main {

    static int N, result;

    static void backtracking(int depth, String medicines) {

        if (medicines.isEmpty()) {
            result++;
            return;
        }
        boolean edibleFirst = false, edibleLast = false;
        if (depth % 3 == 1) {
            if (medicines.charAt(0) == 'l') {
                edibleFirst = true;
            }
            if (medicines.charAt(medicines.length() - 1) == 'l') {
                edibleLast = true;
            }
        } else {
            if (medicines.charAt(0) == 'b' || medicines.charAt(0) == 'd') {
                edibleFirst = true;
            }
            if (medicines.charAt(medicines.length() - 1) == 'b' || medicines.charAt(medicines.length() - 1) == 'd') {
                edibleLast = true;
            }
        }
        if (edibleFirst) {
            backtracking(depth + 1, medicines.substring(1));
        }
        if (medicines.length() == 1) {
            return;
        }
        if (edibleLast) {
            backtracking(depth + 1, medicines.substring(0, medicines.length() - 1));
        }
    }

    public static void main(String[] args) {

        N = new Scanner(System.in).nextInt();
        backtracking(0, "bld".repeat(N));
        System.out.println(result);
    }
}