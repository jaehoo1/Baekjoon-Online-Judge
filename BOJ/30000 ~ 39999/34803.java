import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static Map<String, Integer> substringCount = new HashMap<>();

    static List<String> substrings(String s) {
        List<String> substrings = new ArrayList<>();
        for (int i = 0; i < s.length(); i++) {
            for (int j = i + 1; j <= s.length(); j++) {
                substrings.add(s.substring(i, j));
            }
        }
        return substrings;
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        st.nextToken();
        int N = Integer.parseInt(st.nextToken());
        while (N-- > 0) {
            substrings(br.readLine())
                    .forEach(s -> substringCount.compute(s, (k, v) -> v == null ? 1 : v + 1));
        }
        int K = Integer.parseInt(br.readLine());
        Optional<Map.Entry<String, Integer>> optional = substringCount.entrySet().stream()
                .sorted(Map.Entry.<String, Integer>comparingByValue().reversed())
                .filter(entry -> entry.getKey().length() == K)
                .findFirst();
        System.out.println(optional.isPresent() ? optional.get().getValue() : 0);
    }
}