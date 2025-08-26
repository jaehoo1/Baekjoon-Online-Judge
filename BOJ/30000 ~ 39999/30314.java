import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String prev = br.readLine();
        String enter = br.readLine();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            char p = prev.charAt(i);
            char e = enter.charAt(i);
            cnt += Math.min(p - e < 0 ? p + 26 - e : p - e, e - p < 0 ? e + 26 - p : e - p);
        }
        System.out.println(cnt);
    }
}