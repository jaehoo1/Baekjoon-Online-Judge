import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {

        String S = new BufferedReader(new InputStreamReader(System.in)).readLine();
        int score = 1, preScore = 1;
        for (int i = 1; i < S.length(); i++) {
            if (S.charAt(i) > S.charAt(i - 1)) {
                score += ++preScore;
            } else {
                preScore = 1;
                score += preScore;
            }
        }
        System.out.println(score);
    }
}