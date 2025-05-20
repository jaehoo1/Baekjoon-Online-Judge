import java.io.*;
import java.util.*;

class Node {

    String city;
    Node next;

    public Node(String city, Node next) {
        this.city = city;
        this.next = next;
    }
}

public class Main {

    static Map<String, Node> map;

    static int traversalLength(Node node) {
        Queue<Node> queue = new LinkedList<>();
        queue.add(node);
        int length = 1;
        while (!queue.isEmpty()) {
            Node cur = queue.poll();
            Node next = cur.next;
            if (next == null) {
                return length;
            }
            queue.add(next);
            length++;
        }
        return -1;
    }

    static void traversal(Node node, BufferedWriter bw) throws IOException {
        Queue<Node> queue = new LinkedList<>();
        List<Node> path = new ArrayList<>();
        queue.add(node);
        path.add(node);
        while (!queue.isEmpty()) {
            Node cur = queue.poll();
            Node next = cur.next;
            if (next == null) {
                break;
            }
            queue.add(next);
            path.add(next);
        }
        for (int i = 0; i < path.size() - 1; i++) {
            bw.write(path.get(i).city + "-" + path.get(i + 1).city + " ");
        }
        bw.write("\n");
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());
        for (int t = 1; t <= T; t++) {
            map = new HashMap<>();
            int N = Integer.parseInt(br.readLine());
            for (int i = 0; i < N; i++) {
                String src = br.readLine();
                String dst = br.readLine();
                Node dstNode = map.containsKey(dst) ? map.get(dst) : new Node(dst, null);
                Node srcNode = map.containsKey(src) ? map.get(src) : new Node(src, null);
                srcNode.next = dstNode;
                map.put(src, srcNode);
                map.put(dst, dstNode);
            }
            for (String city : map.keySet()) {
                if (traversalLength(map.get(city)) == N + 1) {
                    bw.write("Case #" + t + ": ");
                    traversal(map.get(city), bw);
                }
            }
        }
        br.close();
        bw.flush();
        bw.close();
    }
}