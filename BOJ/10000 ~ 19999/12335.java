import java.io.*;

public class Main {

    static char[][] board;

    static boolean isWin(char player) {

        for (int i = 0; i < 4; i++) {
            int j = 0;
            for (j = 0; j < 4 && (board[i][j] == player || board[i][j] == 'T'); j++);
            if (j == 4) {
                return true;
            }
            for (j = 0; j < 4 && (board[j][i] == player || board[j][i] == 'T'); j++);
            if (j == 4) {
                return true;
            }
        }
        int i = 0;
        for (i = 0; i < 4 && (board[i][i] == player || board[i][i] == 'T'); i++);
        if (i == 4) {
            return true;
        }
        for (i = 0; i < 4 && (board[i][3 - i] == player || board[i][3 - i] == 'T'); i++);
        return i == 4;
    }

    static boolean isGameFinished() {

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (board[i][j] == '.') {
                    return false;
                }
            }
        }
        return true;
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());
        for (int t = 1; t <= T; t++) {
            board = new char[4][4];
            for (int i = 0; i < 4; i++) {
                board[i] = br.readLine().toCharArray();
            }
            br.readLine();
            bw.write("Case #" + t + ": ");
            if (isWin('X') && isWin('O')) {
                bw.write("Draw\n");
            } else if (isWin('X')) {
                bw.write("X won\n");
            } else if (isWin('O')) {
                bw.write("O won\n");
            } else if (isGameFinished()) {
                bw.write("Draw\n");
            } else {
                bw.write("Game has not completed\n");
            }
        }
        br.close();
        bw.flush();
        bw.close();
    }
}