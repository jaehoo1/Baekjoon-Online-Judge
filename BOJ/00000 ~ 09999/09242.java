import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {

    static final List<Integer>[] NUMBER_POSITIONS = new List[]{
            List.of(0, 1, 2, 3, 5, 6, 8, 9, 11, 12, 13, 14),
            List.of(2, 5, 8, 11, 14),
            List.of(0, 1, 2, 5, 6, 7, 8, 9, 12, 13, 14),
            List.of(0, 1, 2, 5, 6, 7, 8, 11, 12, 13, 14),
            List.of(0, 2, 3, 5, 6, 7, 8, 11, 14),
            List.of(0, 1, 2, 3, 6, 7, 8, 11, 12, 13, 14),
            List.of(0, 1, 2, 3, 6, 7, 8, 9, 11, 12, 13, 14),
            List.of(0, 1, 2, 5, 8, 11, 14),
            List.of(0, 1, 2, 3, 5, 6, 7, 8, 9, 11, 12, 13, 14),
            List.of(0, 1, 2, 3, 5, 6, 7, 8, 11, 12, 13, 14)
    };

    static List<Integer> getPositions(char[][] chars, int y) {

        List<Integer> positions = new ArrayList<>();
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 3; j++) {
                if (chars[i][j + y] == '*') {
                    positions.add(i * 3 + j);
                }
            }
        }
        return positions;
    }

    static boolean isValidNumber(List<Integer> positions) {
        for (int i = 0; i < 10; i++) {
            if (positions.equals(NUMBER_POSITIONS[i])) {
                return true;
            }
        }
        return false;
    }

    static char getNumber(List<Integer> positions) {
        for (int i = 0; i < 10; i++) {
            if (positions.equals(NUMBER_POSITIONS[i])) {
                return (char) (i + '0');
            }
        }
        return 0;
    }

    static boolean isCutAble(String s) {

        return Integer.parseInt(s) % 6 == 0;
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] strings = new String[5];
        for (int i = 0; i < 5; i++) {
            strings[i] = br.readLine();
        }
        char[][] chars = new char[5][strings[0].length()];
        for (int i = 0; i < 5; i++) {
            chars[i] = strings[i].toCharArray();
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < chars[0].length; i += 4) {
            List<Integer> positions = null;
            try {
                positions = getPositions(chars, i);
            } catch (ArrayIndexOutOfBoundsException e) {
                System.out.println("BOOM!!");
                System.exit(0);
            }
            if (!isValidNumber(positions)) {
                System.out.println("BOOM!!");
                System.exit(0);
            }
            sb.append(getNumber(positions));
        }
        System.out.println(isCutAble(sb.toString()) ? "BEER!!" : "BOOM!!");
    }
}