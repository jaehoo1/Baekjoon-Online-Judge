import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        int n = new Scanner(System.in).nextInt();
        long spheres = 0;
        for (int i = 1; i <= n; i++) {
            spheres += (long) i * (n - i + 1);
        }
        System.out.println(spheres);
    }
}