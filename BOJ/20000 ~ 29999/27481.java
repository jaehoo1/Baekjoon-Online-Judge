import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    static boolean[] rooms = new boolean[10];

    static int emptyRoomIndex(char startAt) {
        int i;
        if (startAt == 'L') {
            for (i = 0; i < 10 && rooms[i]; i++);
        } else {
            for (i = 9; i >= 0 && rooms[i]; i--);
        }
        return i;
    }

    static void customerArrive(char startAt) {
        rooms[emptyRoomIndex(startAt)] = true;
    }

    static void customerLeave(int index) {
        rooms[index] = false;
    }

    static void customerLeave(char index) {
        customerLeave(index - '0');
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        char[] chars = br.readLine().toCharArray();
        for (char c : chars) {
            if (c == 'L' || c == 'R') {
                customerArrive(c);
            } else {
                customerLeave(c);
            }
        }
        for (int i = 0; i < 10; i++) {
            System.out.print(rooms[i] ? 1 : 0);
        }
    }
}