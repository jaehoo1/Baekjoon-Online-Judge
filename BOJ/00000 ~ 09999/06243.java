import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int mileage = 0;
        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String originalCity = st.nextToken();
            if (originalCity.equals("#")) {
                break;
            }
            if (originalCity.equals("0")) {
                bw.write(mileage + "\n");
                mileage = 0;
                continue;
            }
            st.nextToken();
            int actualMiles = Integer.parseInt(st.nextToken());
            char classCode = st.nextToken().charAt(0);
            if (classCode == 'F') {
                mileage += actualMiles * 2;
            } else if (classCode == 'B') {
                mileage += Math.round((double) actualMiles * 1.5);
            } else if (actualMiles <= 500) {
                mileage += 500;
            } else {
                mileage += actualMiles;
            }
        }
        br.close();
        bw.flush();
        bw.close();
    }
}