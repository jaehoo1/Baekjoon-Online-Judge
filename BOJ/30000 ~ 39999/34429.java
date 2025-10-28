import java.util.Scanner;
import java.util.StringTokenizer;

class Time {

    int hour, min;
    boolean am;

    public Time(int hour, int min, boolean am) {
        this.hour = hour;
        this.min = min;
        this.am = am;
    }

    void print() {
        System.out.printf("%d:%02d %s", this.hour, this.min, this.am ? "AM" : "PM");
    }

    void minus(int min) {
        while (min-- > 0) {
            this.min--;
            if (this.min < 0) {
                if (this.hour == 12) {
                    this.am = !this.am;
                    this.hour--;
                } else if (this.hour == 1) {
                    this.hour = 12;
                } else {
                    this.hour--;
                }
                this.min += 60;
            }
        }
    }
}

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        String hhmm = sc.next();
        StringTokenizer st = new StringTokenizer(hhmm, ":");
        int h = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        String amPm = sc.next();
        int t = Integer.parseInt(sc.next());

        Time time = new Time(h, m, amPm.equals("AM"));
        time.minus(t);
        time.print();
    }
}