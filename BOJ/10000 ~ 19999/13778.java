import java.io.*;
import java.util.*;

class MP implements Comparable<MP> {

    int id;
    String name;
    int score;

    public MP(int id, String name) {
        this.id = id;
        this.name = name;
        this.score = 0;
    }

    void updateScore(int score) {
        this.score += score;
    }

    void updateScore(String code) {
        if (code.equals("S")) {
            updateScore(10);
        } else if (code.equals("Q")) {
            updateScore(5);
        } else if (code.equals("A")) {
            updateScore(7);
        } else if (code.equals("L")) {
            updateScore(-8);
        } else if (code.equals("F")) {
            updateScore(4);
        } else if (code.equals("D")) {
            updateScore(-5);
        } else if (code.equals("E")) {
            updateScore(-10);
        }
    }

    @Override
    public int compareTo(MP o) {
        if (this.score == o.score) {
            return this.id - o.id;
        }
        return this.score - o.score;
    }
}

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        Map<Integer, MP> map = new HashMap<>();
        for (int i = 0; i < N; i++) {
            String line = br.readLine();
            int spaceIdx = line.indexOf(' ');
            int id = Integer.parseInt(line.substring(0, spaceIdx));
            String name = line.substring(spaceIdx + 1);
            map.put(id, new MP(id, name));
        }
        int A = Integer.parseInt(br.readLine());
        while (A-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            map.get(Integer.parseInt(st.nextToken())).updateScore(st.nextToken());
        }
        List<MP> mps = new ArrayList<>(map.values());
        mps.sort(null);

        int maxScore = mps.get(mps.size() - 1).score;
        int i;
        bw.write(maxScore + " ");
        for (i = 0; i < mps.size() && mps.get(i).score < maxScore; i++);
        for (; i < mps.size() && mps.get(i).score == maxScore; i++) {
            bw.write(mps.get(i).name + " ");
        }
        bw.write("\n");

        int minScore = mps.get(0).score;
        bw.write(minScore + " ");
        for (i = 0; i < mps.size() && mps.get(i).score == minScore; i++) {
            bw.write(mps.get(i).name + " ");
        }
        
        br.close();
        bw.flush();
        bw.close();
    }
}