import java.util.Comparator;
import java.util.Scanner;
import java.util.SortedMap;
import java.util.TreeMap;

public class Main {

    public static void main(String[] args) {

        SortedMap<Integer, String> map = new TreeMap<>(Comparator.reverseOrder());
        Scanner sc = new Scanner(System.in);
        for (int i = 0; i < 7; i++) {
            String seminar = sc.next();
            int applicant = sc.nextInt();
            map.put(applicant, seminar);
        }
        System.out.println(map.values().stream().findFirst().get());
    }
}