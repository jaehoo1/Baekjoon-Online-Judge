import java.io.*;
import java.util.Set;
import java.util.stream.Collectors;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            Set<Character> element = br.readLine()
                    .chars()
                    .mapToObj(c -> (char) c)
                    .collect(Collectors.toSet());
            bw.write(
                    br.readLine()
                            .chars()
                            .mapToObj(c -> (char) c)
                            .allMatch(element::contains)
                                ? "YES\n"
                                : "NO\n"
            );
        }
        br.close();
        bw.flush();
        bw.close();
    }
}