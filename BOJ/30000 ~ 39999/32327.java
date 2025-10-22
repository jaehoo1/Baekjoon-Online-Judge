import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int D = Integer.parseInt(br.readLine());
        String line;
        while ((line = br.readLine()) != null) {
            int size = Integer.parseInt(line);
            if (size >= D) {
                break;
            }
            D += size;
        }
        System.out.println(D);
    }
}