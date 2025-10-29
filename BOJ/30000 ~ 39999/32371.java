import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    static char[][] keyboard = new char[4][10];
    static boolean[][] inputted = new boolean[4][10];

    static void findPosition(char c) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 10; j++) {
                if (keyboard[i][j] == c) {
                    inputted[i][j] = true;
                    return;
                }
            }
        }
    }

    static char getCenter() {
        int[] nx = {-1, -1, 0, 1, 1, 1, 0, -1}, ny = {0, 1, 1, 1, 0, -1, -1, -1};
        for (int i = 1; i < 3; i++) {
            for (int j = 1; j < 9; j++) {
                if (!inputted[i][j]) {
                    continue;
                }
                int k;
                for (k = 0; k < 8; k++) {
                    int nextx = i + nx[k];
                    int nexty = j + ny[k];
                    if (!inputted[nextx][nexty]) {
                        break;
                    }
                }
                if (k == 8) {
                    return keyboard[i][j];
                }
            }
        }
        return '-';
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        for (int i = 0; i < 4; i++) {
            keyboard[i] = br.readLine().toCharArray();
        }
        for (char c : br.readLine().toCharArray()) {
            findPosition(c);
        }
        System.out.println(getCenter());
    }
}