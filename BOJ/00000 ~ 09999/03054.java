import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Scanner;

public class Main {

    static char[][] chars;

    static int getMidIdx(int idx) {
        return idx * 4 + 2;
    }

    static void fill(char c, char frame, int midIdx) {

        for (int i = midIdx - 2; i <= midIdx + 2; i++) {
            chars[0][i] = chars[4][i] = i == midIdx ? frame : '.';
            chars[1][i] = chars[3][i] = i % 2 == 0 ? '.' : frame;
            chars[2][i] = i % 2 == 0 ? frame : '.';
        }
        chars[2][midIdx] = c;
    }

    public static void main(String[] args) throws IOException {

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String s = new Scanner(System.in).next();
        chars = new char[5][s.length() * 5 - s.length() + 1];
        for (int i = 0; i < s.length(); i++) {
            if (i % 3 == 2) {
                continue;
            }
            fill(s.charAt(i), '#', getMidIdx(i));
        }
        for (int i = 0; i < s.length(); i++) {
            if (i % 3 != 2) {
                continue;
            }
            fill(s.charAt(i), '*', getMidIdx(i));
        }
        for (int i = 0; i < 5; i++) {
            bw.write(new String(chars[i]) + "\n");
        }
        bw.flush();
        bw.close();
    }
}