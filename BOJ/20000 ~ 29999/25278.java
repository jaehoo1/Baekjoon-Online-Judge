import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int water = 0;
        int temperature = -30;
        int oxygen = 0;
        int n = Integer.parseInt(br.readLine());
        while (n-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String parameter = st.nextToken();
            int integer = Integer.parseInt(st.nextToken());
            if ("ocean".equals(parameter)) {
                water += integer;
            } else if ("temperature".equals(parameter)) {
                temperature += integer;
            } else if ("oxygen".equals(parameter)) {
                oxygen += integer;
            }
        }
        System.out.println((water >= 9 && oxygen >= 14 && temperature >= 8) ? "liveable" : "not liveable");
    }
}