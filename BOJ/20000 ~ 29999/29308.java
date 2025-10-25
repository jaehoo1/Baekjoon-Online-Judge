import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int max = 0;
        String maxName = null;
        while (n-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int salary = Integer.parseInt(st.nextToken());
            String name = st.nextToken();
            String nation = st.nextToken();
            if (!nation.equals("Russia")) {
                continue;
            }
            if (salary > max) {
                max = salary;
                maxName = name;
            }
        }
        System.out.println(maxName);
    }
}