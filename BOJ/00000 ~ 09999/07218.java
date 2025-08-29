import java.util.Scanner;
import java.util.stream.IntStream;

public class Main {

    static final String[] NUMBERS = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X", "XI", "XII"};

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        sc.nextLine();
        String s = sc.nextLine();
        IntStream.range(1, NUMBERS.length)
                .filter(i -> s.contains(NUMBERS[i]))
                .forEach(i -> System.out.print(i + " "));
    }
}