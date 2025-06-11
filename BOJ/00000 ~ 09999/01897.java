import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    
    static Map<String, List<String>> map = new HashMap<>();

    static boolean isEdge(String s1, String s2) {

        if (s1.length() + 1 != s2.length()) {
            return false;
        }
        boolean added = false;
        for (int i = 0, j = 0; i < s1.length() && j < s2.length(); ) {
            if (s1.charAt(i) == s2.charAt(j)) {
                i++;
                j++;
            } else if (!added) {
                added = true;
                j++;
            } else {
                return false;
            }
        }
        return true;
    }

    static String bfs(String start) {

        int maxLength = 0;
        String result = null;
        Queue<String> queue = new LinkedList<>();
        queue.add(start);
        while (!queue.isEmpty()) {
            String cur = queue.poll();
            if (cur.length() > maxLength) {
                maxLength = cur.length();
                result = cur;
            }
            for (String next : map.get(cur)) {
                queue.add(next);
            }
        }
        return result;
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int d = Integer.parseInt(st.nextToken());
        String first = st.nextToken();
        String[] dict = new String[d];
        for (int i = 0; i < d; i++) {
            dict[i] = br.readLine();
            map.put(dict[i], new ArrayList<>());
        }
        for (int i = 0; i < d; i++) {
            for (int j = i + 1; j < d; j++) {
                if (isEdge(dict[i], dict[j])) {
                    map.get(dict[i]).add(dict[j]);
                }
                if (isEdge(dict[j], dict[i])) {
                    map.get(dict[j]).add(dict[i]);
                }
            }
        }
        System.out.println(bfs(first));
    }
}