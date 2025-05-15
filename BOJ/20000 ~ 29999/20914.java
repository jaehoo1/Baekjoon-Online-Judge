import java.util.*;

public class Main {

    static List<Character>[] edges = new ArrayList[26];

    static void appendEdges(char node, String s) {
        for (int i = 0; i < s.length(); i++) {
            edges[node - 'A'].add(s.charAt(i));
        }
    }

    static int bfs(char start, char end) {
        boolean[] visited = new boolean[26];
        int move = 0;
        Queue<Character> queue = new LinkedList<>();
        visited[start - 'A'] = true;
        queue.add(start);
        while (!queue.isEmpty()) {
            int queueSize = queue.size();
            for (int i = 0; i < queueSize; i++) {
                char cur = queue.poll();
                if (cur == end) {
                    return move;
                }
                for (int j = 0; j < edges[cur - 'A'].size(); j++) {
                    char next = edges[cur - 'A'].get(j);
                    if (visited[next - 'A']) {
                        continue;
                    }
                    visited[next - 'A'] = true;
                    queue.add(next);
                }
            }
            move++;
        }
        return -1;
    }

    public static void main(String[] args) {

        for (int i = 0; i < 26; i++) {
            edges[i] = new ArrayList<>();
        }

        appendEdges('Q', "WA");
        appendEdges('W', "QEAS");
        appendEdges('E', "WRSD");
        appendEdges('R', "ETDF");
        appendEdges('T', "RYFG");
        appendEdges('Y', "TUGH");
        appendEdges('U', "YIHJ");
        appendEdges('I', "UOJK");
        appendEdges('O', "IPKL");
        appendEdges('P', "OL");
        appendEdges('A', "QWSZ");
        appendEdges('S', "WEADZX");
        appendEdges('D', "ERSFXC");
        appendEdges('F', "RTDGCV");
        appendEdges('G', "TYFHVB");
        appendEdges('H', "YUGJBN");
        appendEdges('J', "UIHKNM");
        appendEdges('K', "IOJLM");
        appendEdges('L', "OPK");
        appendEdges('Z', "ASX");
        appendEdges('X', "ZSDC");
        appendEdges('C', "XDFV");
        appendEdges('V', "CFGB");
        appendEdges('B', "VGHN");
        appendEdges('N', "BHJM");
        appendEdges('M', "NJK");

        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        sc.nextLine();
        while (T-- > 0) {
            String s = sc.nextLine();
            int time = s.length();
            for (int i = 1; i < s.length(); i++) {
                time += bfs(s.charAt(i - 1), s.charAt(i)) * 2;
            }
            System.out.println(time);
        }
    }
}
