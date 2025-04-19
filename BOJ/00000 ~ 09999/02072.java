import java.util.Scanner;

public class Main {

    static char[][] arr = new char[19][19];

    static boolean isWinOnLine(String s) {

        if (!s.contains("bbbbbb") && s.contains("bbbbb")) {
            return true;
        }
        if (!s.contains("wwwwww") && s.contains("wwwww")) {
            return true;
        }
        return false;
    }

    static boolean isWinOnLine(StringBuilder sb) {

        return isWinOnLine(sb.toString());
    }

    static boolean isWin() {

        for (int i = 0; i < 19; i++) {
            StringBuilder right = new StringBuilder();
            StringBuilder down = new StringBuilder();
            StringBuilder rightDown1 = new StringBuilder();
            StringBuilder rightDown2 = new StringBuilder();
            StringBuilder rightUp1 = new StringBuilder();
            StringBuilder rightUp2 = new StringBuilder();
            for (int j = 0; j < 19; j++) {
                right.append(arr[i][j]);
                down.append(arr[j][i]);
            }
            for (int j = 0; j <= i; j++) {
                rightDown1.append(arr[18 - i + j][j]);
                rightDown2.append(arr[j][18 - i + j]);
                rightUp1.append(arr[i - j][j]);
                rightUp2.append(arr[18 - j][18 - i + j]);
            }
            if (isWinOnLine(right) || isWinOnLine(down) || isWinOnLine(rightDown1) || isWinOnLine(rightUp1) || isWinOnLine(rightDown2) || isWinOnLine(rightUp2)) {
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int N, x, y;
        N = sc.nextInt();
        for (int i = 0; i < N; i++) {
            x = sc.nextInt();
            y = sc.nextInt();
            arr[x - 1][y - 1] = i % 2 == 0 ? 'b' : 'w';
            if (isWin()) {
                System.out.println(i + 1);
                System.exit(0);
            }
        }
        System.out.println(-1);
    }
}