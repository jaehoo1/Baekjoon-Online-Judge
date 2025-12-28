import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        double mari = 0, juri = 0;
        int M = 0, J = 0;
        int N = Integer.parseInt(br.readLine());
        while (N-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String player = st.nextToken();
            int points = Integer.parseInt(st.nextToken());
            if (player.equals("M")) {
                mari += points;
                M++;
            } else {
                juri += points;
                J++;
            }
        }
        mari = M == 0 ? 0 : mari / M;
        juri = J == 0 ? 0 : juri / J;
        if (mari > juri) {
            System.out.println("M");
        } else if (mari < juri) {
            System.out.println("J");
        } else {
            System.out.println("V");
        }
    }
}