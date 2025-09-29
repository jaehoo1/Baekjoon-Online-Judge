import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {

        boolean[][] seats = new boolean[10][20];
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int N = Integer.parseInt(br.readLine());
        while (N-- > 0) {
            String seat = br.readLine();
            char row = seat.charAt(0);
            int col = Integer.parseInt(seat.substring(1));
            seats[row - 'A'][col - 1] = true;
        }
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 20; j++) {
                bw.write(seats[i][j] ? 'o' : '.');
            }
            bw.write("\n");
        }
        br.close();
        bw.flush();
        bw.close();
    }
}