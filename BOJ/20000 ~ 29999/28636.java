import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int hh = 0;
        int mm = 0;
        int ss = 0;
        while (n-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine(), ":");
            mm += Integer.parseInt(st.nextToken());
            ss += Integer.parseInt(st.nextToken());
        }
        mm += ss / 60;
        ss %= 60;
        hh += mm / 60;
        mm %= 60;
        System.out.printf("%02d:%02d:%02d%n", hh, mm, ss);
    }
}