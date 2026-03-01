import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int r = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());
        char[][] grid = new char[r][c];
        for (int i = 0; i < r; i++) {
            grid[i] = br.readLine().toCharArray();
        }
        for (int j = 0; j < c; j++) {
            for (int i = 0; i < r; i++) {
                if (grid[i][j] != '.') {
                    bw.write(grid[i][j]);
                }
            }
        }
        bw.flush();
        br.close();
        bw.close();
    }
}