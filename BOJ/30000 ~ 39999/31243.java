import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int timeToMin(int hour, int min) {
        return hour * 60 + min;
    }

    static int timeToMin(String hour, String min) {
        return timeToMin(Integer.parseInt(hour), Integer.parseInt(min));
    }

    static int diff(int startMin, int endMin) {
        return endMin < startMin ? endMin + 60 * 24 - startMin : endMin - startMin;
    }

    static void print(int min) {
        System.out.printf("%d:%02d\n", min / 60, min % 60);
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int min = 60 * 24;
        int max = 0;
        for (int i = 0; i < 3; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int start = timeToMin(st.nextToken(), st.nextToken());
            int end = timeToMin(st.nextToken(), st.nextToken());
            int diff = diff(start, end);
            min = Math.min(min, diff);
            max = Math.max(max, diff);
        }
        print(min);
        print(max);
    }
}