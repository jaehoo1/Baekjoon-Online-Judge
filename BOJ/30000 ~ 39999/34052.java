import java.util.Scanner;
import java.util.stream.IntStream;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        System.out.println(IntStream.range(0, 4).map(i -> sc.nextInt()).sum() <= 1500 ? "Yes" : "No");
    }
}