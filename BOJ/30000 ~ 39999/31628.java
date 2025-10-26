import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[][] eggplants = new String[10][10];
        for (int i = 0; i < 10; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 10; j++) {
                eggplants[i][j] = st.nextToken();
            }
        }
        boolean line = false;
        for (int i = 0; i < 10; i++) {
            int j;
            for (j = 1; j < 10 && eggplants[i][0].equals(eggplants[i][j]); j++);
            if (j == 10) {
                line = true;
            }
            for (j = 1; j < 10 && eggplants[0][i].equals(eggplants[j][i]); j++);
            if (j == 10) {
                line = true;
            }
        }
        System.out.println(line ? 1 : 0);
    }
}