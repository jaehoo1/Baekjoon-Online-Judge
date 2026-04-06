import java.io.*;
import java.util.HashSet;
import java.util.Set;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int K = Integer.parseInt(br.readLine());
        for (int k = 1; k <= K; k++) {
            int n = Integer.parseInt(br.readLine());
            Set<Character> announce = new HashSet<>();
            for (char c : br.readLine().toCharArray()) {
                announce.add(c);
            }
            int received = 0;
            while (n-- > 0) {
                String consumedMedias = br.readLine();
                for (char c : consumedMedias.toCharArray()) {
                    if (announce.contains(c)) {
                        received++;
                        break;
                    }
                }
            }
            bw.write("Data Set " + k + ":\n");
            bw.write(received + "\n\n");
        }
        br.close();
        bw.flush();
        bw.close();
    }
}