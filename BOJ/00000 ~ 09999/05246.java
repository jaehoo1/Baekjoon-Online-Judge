import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.stream.IntStream;

class Piece {

    int x, y;

    public Piece(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            Piece[] pieces = new Piece[N];
            for (int i = 0; i < N; i++) {
                int c = Integer.parseInt(st.nextToken());
                int r = Integer.parseInt(st.nextToken());
                pieces[i] = new Piece(r, c);
            }
            bw.write(IntStream.rangeClosed(1, 8)
                    .mapToLong(i -> Arrays.stream(pieces).filter(piece -> piece.x == i).count())
                    .max()
                    .getAsLong() + "\n");
        }
        br.close();
        bw.flush();
        bw.close();
    }
}