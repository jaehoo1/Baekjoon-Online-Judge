import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int aoi = 0, bitaro = 0;
        String S = br.readLine();
        String T = br.readLine();
        for (int i = 0; i < N; i++) {
            char a = S.charAt(i);
            char b = T.charAt(i);
            if ((a == 'R' && b == 'S') || (a == 'P' && b == 'R') || (a == 'S' && b == 'P')) {
                aoi++;
            } else if ((b == 'R' && a == 'S') || (b == 'P' && a == 'R') || (b == 'S' && a == 'P')) {
                bitaro++;
            }
        }
        System.out.println(aoi + " " + bitaro);
    }
}