import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
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

    void multiply(int multiple) {
        this.hour *= multiple;
        this.min *= multiple;
        this.hour += this.min / 60;
        this.min %= 60;
    }

    void print() {
        System.out.printf("%d:%02d", this.hour, this.min);
    }
}

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        br.readLine();
        StringTokenizer st = new StringTokenizer(br.readLine(), ":");
        Time time = new Time(st.nextToken(), st.nextToken());
        int multiple = 1;
        String day = br.readLine();
        if (day.equals("sat") || day.equals("sun")) {
            multiple *= 2;
        }
        if (br.readLine().equals("1")) {
            multiple *= 2;
        }
        if (br.readLine().equals("1")) {
            multiple *= 3;
        }
        if (br.readLine().equals("1")) {
            multiple *= 3;
        }
        time.multiply(multiple);
        time.print();
    }
}