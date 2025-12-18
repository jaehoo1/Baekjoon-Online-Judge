import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

public class Main {

    static Set<String> permutations;

    static void recur(char[] chars, char[] tree, boolean[] visited, int depth, int length) {

        if (depth == length) {
            permutations.add(new String(tree));
            return;
        }
        for (int i = 0; i < length; i++) {
            if (visited[i]) {
                continue;
            }
            visited[i] = true;
            tree[depth] = chars[i];
            recur(chars, tree, visited, depth + 1, length);
            visited[i] = false;
        }
    }

    static List<String> getPermutations(char[] chars) {

        permutations = new HashSet<>();
        recur(chars, new char[chars.length], new boolean[chars.length], 0, chars.length);
        return permutations.stream().sorted().collect(Collectors.toList());
    }

    static List<String> getPermutations(String s) {
        return getPermutations(s.toCharArray());
    }

    static String findNext(List<String> permutations, String A) {

        int index = permutations.indexOf(A);
        if (index + 1 == permutations.size()) {
            return "USELESS";
        }
        return permutations.get(index + 1);
    }

    static String findNext(String A) {
        return findNext(getPermutations(A), A);
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            bw.write(findNext(br.readLine()) + "\n");
        }
        br.close();
        bw.flush();
        bw.close();
    }
}