import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        while (true) {
            int n = Integer.parseInt(br.readLine());
            if (n == 0) {
                break;
            }
            int[] rows = new int[n];
            int[] columns = new int[n];
            int rowsOddCnt = 0;
            int columnsOddCnt = 0;
            for (int i = 0; i < n; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                for (int j = 0; j < n; j++) {
                    int bit = Integer.parseInt(st.nextToken());
                    if (bit == 1) {
                        rows[i]++;
                        columns[j]++;
                    }
                }
            }
            
            for (int i = 0; i < n; i++) {
                if (rows[i] % 2 == 1) {
                    rowsOddCnt++;
                }
                if (columns[i] % 2 == 1) {
                    columnsOddCnt++;
                }
            }
            
            if (rowsOddCnt == 0 && columnsOddCnt == 0) {
                bw.write("OK\n");
            } else if (rowsOddCnt == 1 && columnsOddCnt == 1) {
                int row, column, i;
                for (i = 0; i < n && rows[i] % 2 == 0; i++) ;
                row = i;
                for (i = 0; i < n && columns[i] % 2 == 0; i++) ;
                column = i;
                bw.write("Change bit (" + (row + 1) + "," + (column + 1) + ")\n");
            } else {
                bw.write("Corrupt\n");
            }
        }
        br.close();
        bw.flush();
        bw.close();
    }
}