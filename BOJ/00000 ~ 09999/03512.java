import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());
        int totalArea = 0;
        int totalAreaOfBedrooms = 0;
        double reducedTotalArea = 0;
        while (n-- > 0) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            String t = st.nextToken();
            totalArea += a;
            if ("bedroom".equals(t)) {
                totalAreaOfBedrooms += a;
            }
            reducedTotalArea += "balcony".equals(t) ? (double) a / 2 : a;
        }
        System.out.println(totalArea);
        System.out.println(totalAreaOfBedrooms);
        System.out.println(reducedTotalArea * c);
    }
}