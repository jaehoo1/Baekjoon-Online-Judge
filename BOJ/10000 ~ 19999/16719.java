import java.util.*;

class StringWithNewChar implements Comparable<StringWithNewChar> {

    String s;
    int newCharIdx;

    public StringWithNewChar(String s, int newCharIdx) {
        this.s = s;
        this.newCharIdx = newCharIdx;
    }

    @Override
    public int compareTo(StringWithNewChar o) {
        int compared = this.s.compareTo(o.s);
        if (compared == 0) {
            return this.newCharIdx < o.newCharIdx ? -1 : 1;
        }
        return compared;
    }
}

public class Main {

    static boolean[] visited = new boolean[100];
    static char[] chars;

    static void recur(int depth) {

        if (depth == chars.length) {
            System.exit(0);
        }
        StringWithNewChar stringWithNewChar = nextCharIndex();
        System.out.println(stringWithNewChar.s);
        visited[stringWithNewChar.newCharIdx] = true;
        recur(depth + 1);
    }

    static StringWithNewChar nextCharIndex() {

        List<StringWithNewChar> newStrings = new ArrayList<>();
        for (int i = 0; i < chars.length; i++) {
            if (visited[i]) {
                continue;
            }
            StringBuilder sb = new StringBuilder();
            for (int j = 0; j < chars.length; j++) {
                if (visited[j] || j == i) {
                    sb.append(chars[j]);
                }
            }
            newStrings.add(new StringWithNewChar(sb.toString(), i));
        }
        Collections.sort(newStrings);
        return newStrings.get(0);
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        chars = sc.next().toCharArray();
        recur(0);
    }
}