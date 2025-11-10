import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        char[] me = br.readLine().toCharArray();
        char[] guile = br.readLine().toCharArray();
        int win = 0, lose = 0;
        for (int i = 0; i < n; i++) {
            if (me[i] == guile[i]) {
                continue;
            }
            if (me[i] == 'R') {
                if (guile[i] == 'P') {
                    lose++;
                } else if (guile[i] == 'S') {
                    win++;
                }
            } else if (me[i] == 'P') {
                if (guile[i] == 'R') {
                    win++;
                } else if (guile[i] == 'S') {
                    lose++;
                }
            } else if (me[i] == 'S') {
                if (guile[i] == 'R') {
                    lose++;
                } else if (guile[i] == 'P') {
                    win++;
                }
            }
        }
        System.out.println(win > lose ? "victory" : "defeat");
    }
}