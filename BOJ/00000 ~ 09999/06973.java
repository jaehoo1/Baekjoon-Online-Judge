import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());
        while (T-- > 0) {

            Map<String, Integer> dict = new HashMap<>();
            int dictIdx = 0;

            while (true) {
                String line = br.readLine();
                if (line == null || line.isEmpty()) {
                    break;
                }

                StringTokenizer st = new StringTokenizer(line);
                List<String> printWords = new ArrayList<>();

                while (st.hasMoreTokens()) {
                    String word = st.nextToken();
                    if (dict.containsKey(word)) {
                        printWords.add(String.valueOf(dict.get(word)));
                    } else {
                        dict.put(word, ++dictIdx);
                        printWords.add(word);
                    }
                }

                bw.write(String.join(" ", printWords) + "\n");
            }
            bw.write("\n");
        }

        br.close();
        bw.flush();
        bw.close();
    }
}