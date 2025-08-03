import java.util.Scanner;
import java.util.Set;

public class Main {

    static final Set<String> DIGITAL_HUMANITIES = Set.of("social", "history", "language", "literacy");

    public static void main(String[] args) {

        String string = new Scanner(System.in).nextLine();
        DIGITAL_HUMANITIES.forEach(digitalHumanity -> {
            if (string.contains(digitalHumanity)) {
                System.out.println("digital humanities");
                System.exit(0);
            }
        });
        System.out.println("public bigdata");
    }
}