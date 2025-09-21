import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String word = br.readLine();
        String line;
        int cou = 0;
        while ((line = br.readLine()) != null) {
            int idx = line.indexOf(word);
            while (idx >= 0) {
                cou++;
                idx = line.indexOf(word, idx + 1);
            }
        }
        System.out.println(cou);
    }
}