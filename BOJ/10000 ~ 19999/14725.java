import java.io.*;
import java.util.*;

class Node implements Comparable<Node> {

    int depth;
    String food;
    Node parent;
    List<Node> nextNodes;

    public Node(int depth, String food, Node parent) {
        this.depth = depth;
        this.food = food;
        this.parent = parent;
        this.nextNodes = new ArrayList<>();
    }

    void appendChild(Node node) {
        if (nextNodes.contains(node)) {
            return;
        }
        nextNodes.add(node);
    }

    void printNode() throws IOException {
        if (depth == 0) {
            return;
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 1; i < depth; i++) {
            sb.append("--");
        }
        Main.bw.write(sb.append(food) + "\n");
    }

    void dfs() throws IOException {
        printNode();
        Collections.sort(nextNodes);
        for (Node child : nextNodes) {
            child.dfs();
        }
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Node node = (Node) o;
        return depth == node.depth && Objects.equals(food, node.food) && Objects.equals(parent, node.parent);
    }

    @Override
    public int compareTo(Node o) {
        return food.compareTo(o.food);
    }
}

public class Main {

    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        List<Node> nodes = new ArrayList<>();
        Node root = new Node(0, null, null);
        nodes.add(root);

        int N = Integer.parseInt(br.readLine());
        while (N-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int K = Integer.parseInt(st.nextToken());
            Node preNode = new Node(1, st.nextToken(), root);
            if (!nodes.contains(preNode)) {
                nodes.add(preNode);
                root.appendChild(preNode);
            } else {
                preNode = nodes.get(nodes.indexOf(preNode));
            }
            for (int i = 2; i <= K; i++) {
                Node node = new Node(i, st.nextToken(), preNode);
                if (!nodes.contains(node)) {
                    nodes.add(node);
                } else {
                    node = nodes.get(nodes.indexOf(node));
                }
                preNode.appendChild(node);
                preNode = node;
            }
        }
        root.dfs();
        br.close();
        bw.flush();
        bw.close();
    }
}