import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {

    static final String[] ZODIAC_SIGNS = {"", "Aquarius", "Pisces", "Aries", "Taurus", "Gemini", "Cancer", "Leo", "Virgo", "Libra", "Scorpio", "Sagittarius", "Capricorn"};
    static final int[] DAYS = {-1, 20, 19, 21, 20, 21, 21, 23, 23, 23, 23, 23, 22};

    public static void main(String[] args) {
        StringTokenizer st = new StringTokenizer(new Scanner(System.in).nextLine(), "-");
        st.nextToken();
        int month = Integer.parseInt(st.nextToken());
        int day = Integer.parseInt(st.nextToken());
        int index = month + (day >= DAYS[month] ? 0 : -1);
        if (index == 0) {
            index = 12;
        }
        if (index > 12) {
            index = 1;
        }
        System.out.println(ZODIAC_SIGNS[index]);
    }
}