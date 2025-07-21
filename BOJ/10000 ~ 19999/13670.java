import java.io.*;
import java.util.StringTokenizer;

class Time {

    int hour, min;

    public Time(int hour, int min) {
        this.hour = hour;
        this.min = min;
    }

    public Time(String hour, String min) {
        this(Integer.parseInt(hour), Integer.parseInt(min));
    }

    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Time time = (Time) o;
        return hour == time.hour && min == time.min;
    }

    void plus() {
        this.min++;
        if (this.min >= 60) {
            this.min = 0;
            this.hour++;
        }
        if (this.hour >= 24) {
            this.hour = 0;
        }
    }

    int between(Time time) {
        int minute = 0;
        while (!this.equals(time)) {
            this.plus();
            minute++;
        }
        return minute;
    }
}

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String H1 = st.nextToken();
            String M1 = st.nextToken();
            String H2 = st.nextToken();
            String M2 = st.nextToken();
            if (H1.equals("0") && M1.equals("0") && H2.equals("0") && M2.equals("0")) {
                break;
            }
            bw.write(new Time(H1, M1).between(new Time(H2, M2)) + "\n");
        }
        br.close();
        bw.flush();
        bw.close();
    }
}