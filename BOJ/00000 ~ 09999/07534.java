import java.io.*;
import java.util.*;

class Nodes {

    Map<String, Node> map;

    public Nodes() {
        this.map = new HashMap<>();
    }

    boolean isNodeExists(String key) {
        return map.containsKey(key);
    }

    void createNode(String key) {
        map.put(key, new Node(key));
    }

    void connectNode(String u, String v) {
        Node pre = map.get(u);
        Node next = map.get(v);
        pre.setNext(next);
        next.setPre(pre);
    }

    String traversal() {
        StringBuilder sb = new StringBuilder();
        Node root = map.values()
                .stream()
                .filter(node -> node.getPre() == null)
                .findFirst()
                .get();
        while (root != null) {
            sb.append(root.step + "\n");
            root = root.getNext();
        }
        return sb.append("\n").toString();
    }
}

class Node {

    String step;
    Node pre, next;

    public Node(String step, Node pre, Node next) {
        this.step = step;
        this.pre = pre;
        this.next = next;
    }

    public Node(String step) {
        this(step, null, null);
    }

    public Node getPre() {
        return pre;
    }

    public void setPre(Node pre) {
        this.pre = pre;
    }

    public Node getNext() {
        return next;
    }

    public void setNext(Node next) {
        this.next = next;
    }
}

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());
        for (int t = 1; t <= T; t++) {
            Nodes nodes = new Nodes();
            int S = Integer.parseInt(br.readLine());
            for (int i = 0; i < S - 1; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                String u = st.nextToken();
                String v = st.nextToken();
                if (!nodes.isNodeExists(u)) {
                    nodes.createNode(u);
                }
                if (!nodes.isNodeExists(v)) {
                    nodes.createNode(v);
                }
                nodes.connectNode(u, v);
            }
            bw.write("Scenario #" + t + ":\n");
            bw.write(nodes.traversal());
        }
        br.close();
        bw.flush();
        bw.close();
    }
}