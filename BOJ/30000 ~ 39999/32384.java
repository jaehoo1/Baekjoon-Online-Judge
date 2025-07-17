import java.util.Scanner;
import java.util.stream.IntStream;

public class Main {

    public static void main(String[] args) {

        IntStream.range(0, new Scanner(System.in).nextInt())
                .forEach((i) -> System.out.print("LoveisKoreaUniversity "));
    }
}