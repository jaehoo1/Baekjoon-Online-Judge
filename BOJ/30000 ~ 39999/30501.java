import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        while (N-- > 0) {
            String name = br.readLine();
            if (name.contains("S")) {
                System.out.println(name);
            }
        }
    }
}