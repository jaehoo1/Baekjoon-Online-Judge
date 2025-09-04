import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

class LedRecord implements Comparable<LedRecord> {

    int time;
    boolean on;

    public LedRecord(int M, int O) {
        this.time = M;
        this.on = O == 1;
    }

    @Override
    public int compareTo(LedRecord o) {
        return this.time - o.time;
    }
}

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        LedRecord[] ledRecords = new LedRecord[N];
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int M = Integer.parseInt(st.nextToken());
            int O = Integer.parseInt(st.nextToken());
            ledRecords[i] = new LedRecord(M, O);
        }
        Arrays.sort(ledRecords);
        for (LedRecord ledRecord : ledRecords) {
            if (!ledRecord.on) {
                System.out.println(ledRecord.time);
                System.exit(0);
            }
        }
        System.out.println(-1);
    }
}