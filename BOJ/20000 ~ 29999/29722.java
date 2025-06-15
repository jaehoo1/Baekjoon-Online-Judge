import java.util.Arrays;
import java.util.Scanner;

class Date {

    int year, month, date;

    public Date(String date) {
        int[] array = Arrays.stream(date.split("-"))
                .mapToInt(Integer::parseInt)
                .toArray();
        this.year = array[0];
        this.month = array[1];
        this.date = array[2];
    }

    @Override
    public String toString() {
        return year + "-" + String.format("%02d", month) + "-" + String.format("%02d", date);
    }

    void plusDate(int date) {
        int year = date / 360;
        date %= 360;
        int month = date / 30;
        date %= 30;

        this.date += date;
        while (this.date > 30) {
            this.date -= 30;
            this.month++;
        }
        this.month += month;
        while (this.month > 12) {
            this.month -= 12;
            this.year++;
        }
        this.year += year;
    }
}

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        Date date = new Date(sc.nextLine());
        date.plusDate(sc.nextInt());
        System.out.println(date);
    }
}