import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        System.out.println(new Scanner(System.in).next().matches("^io[0-9]+$") ? "Correct" : "Incorrect");
    }
}