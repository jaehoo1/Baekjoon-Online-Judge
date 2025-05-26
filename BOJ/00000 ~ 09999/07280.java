import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        final char[] SUITS = {'S', 'B', 'V', 'K'};
        boolean[][] deck = new boolean[4][13];
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        for (int i = 0; i < 51; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            char suit = st.nextToken().charAt(0);
            int num = Integer.parseInt(st.nextToken());
            for (int j = 0; j < 4; j++) {
                if (suit != SUITS[j]) {
                    continue;
                }
                deck[j][num - 1] = true;
            }
        }
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 13; j++) {
                if (deck[i][j]) {
                    continue;
                }
                System.out.println(SUITS[i] + " " + (j + 1));
            }
        }
    }
}