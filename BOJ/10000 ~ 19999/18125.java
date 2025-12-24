import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int[][] rotate(int[][] arr) {
        int R = arr[0].length;
        int C = arr.length;
        int[][] result = new int[R][C];
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                result[i][j] = arr[j][R- 1 - i];
            }
        }
        return result;
    }

    static String cat(boolean isEdible) {
        return (isEdible ? """
                |>___/|        /}
                | O < |       / }
                (==0==)------/ }
                | ^  _____    |
                |_|_/     ||__|
                """ : """
                                        |>___/|     /}
                | O O |    / }
                ( =0= )\"\"\"\"  \\
                | ^  ____    |
                |_|_/    ||__|
                """).trim();
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int R = Integer.parseInt(st.nextToken());
        int C = Integer.parseInt(st.nextToken());
        int[][] rotated = new int[C][R];
        for (int i = 0; i < C; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < R; j++) {
                rotated[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        int[][] origin = new int[R][C];
        for (int i = 0; i < R; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < C; j++) {
                origin[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        System.out.println(cat(Arrays.deepEquals(rotate(origin), rotated)));
    }
}