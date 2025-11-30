import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        boolean[][] visited = new boolean[4][3];
        boolean unlocked = false;
        String s = new Scanner(System.in).next();
        for (int i = 0; i < 3; i++) {
            int num = Integer.parseInt(String.valueOf(s.charAt(i))) - 1;
            if (num < 0) {
                num = 10;
            }
            visited[num / 3][num % 3] = true;
        }
        for (int i = 0; i < 3; i++) {
            int j;
            for (j = 0; j < 3 && visited[i][j]; j++);
            if (j == 3) {
                unlocked = true;
            }
            for (int k = 0; k <= 1; k++) {
                for (j = k; j < k + 3 && visited[j][i]; j++);
                if (j == k + 3) {
                    unlocked = true;
                }
            }
        }
        System.out.println(unlocked ? "Unlocked" : "Locked");
    }
}