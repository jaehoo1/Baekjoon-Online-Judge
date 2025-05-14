import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        br.readLine();
        int preLength = 1;
        StringTokenizer st = new StringTokenizer(br.readLine());
        while (st.hasMoreTokens()) {
            String word = st.nextToken();
            if (preLength > word.length()) {
                sb.append(' ');
            } else {
                sb.append(word.charAt(preLength - 1));
            }
            preLength = word.length();
        }
        System.out.println(sb);
    }
}
