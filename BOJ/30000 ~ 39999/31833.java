import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        br.readLine();
        long A = Long.parseLong(String.join("", br.readLine().split(" ")));
        long B = Long.parseLong(String.join("", br.readLine().split(" ")));
        System.out.println(A < B ? A : B);
    }
}