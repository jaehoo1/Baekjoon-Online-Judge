import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        StringTokenizer st = new StringTokenizer(sc.nextLine(), ":");
        int today = Integer.parseInt(st.nextToken()) * 60 + Integer.parseInt(st.nextToken());
        st = new StringTokenizer(sc.nextLine(), ":");
        int tomorrow = Integer.parseInt(st.nextToken()) * 60 + Integer.parseInt(st.nextToken()) + 60 * 24;
        tomorrow -= today;
        System.out.printf("%02d:%02d", tomorrow / 60, tomorrow % 60);
    }
}