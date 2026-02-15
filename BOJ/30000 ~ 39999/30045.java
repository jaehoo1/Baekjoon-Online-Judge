import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int result = 0;
        while (N-- > 0) {
            String S = br.readLine();
            if (S.contains("01") || S.contains("OI")) {
                result++;
            }
        }
        System.out.println(result);
    }
}