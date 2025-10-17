import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] firstDie = new int[n];
        int[] secondDie = new int[n];
        int win = 0, lose = 0;
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            firstDie[i] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            secondDie[i] = Integer.parseInt(st.nextToken());
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (firstDie[i] > secondDie[j]) {
                    win++;
                } else if (firstDie[i] < secondDie[j]) {
                    lose++;
                }
            }
        }
        String result;
        if (win > lose) {
            result = "first";
        } else if (win < lose) {
            result = "second";
        } else {
            result = "tie";
        }
        System.out.println(result);
    }
}