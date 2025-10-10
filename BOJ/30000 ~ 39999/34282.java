import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int sum = sc.nextInt() + sc.nextInt() + sc.nextInt() * 2;
        char grade;
        if (sum >= 360) {
            grade = 'A';
        } else if (sum >= 320) {
            grade = 'B';
        } else if (sum >= 280) {
            grade = 'C';
        } else if (sum >= 240) {
            grade = 'D';
        } else {
            grade = 'F';
        }
        System.out.println(grade);
    }
}