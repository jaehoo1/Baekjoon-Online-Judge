import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

class Participant implements Comparable<Participant> {

    String name;
    int score;
    boolean isHidden;

    public Participant(String s) {
        StringTokenizer st = new StringTokenizer(s, ",");
        String name = st.nextToken();
        String score = st.nextToken();
        String isHidden = st.nextToken();
        st = new StringTokenizer(name, ":");
        st.nextToken();
        name = st.nextToken();
        st = new StringTokenizer(name, "\"");
        this.name = st.nextToken();
        st = new StringTokenizer(score, ":");
        st.nextToken();
        this.score = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(isHidden, ":");
        st.nextToken();
        this.isHidden = st.nextToken().charAt(0) == '1';
    }

    @Override
    public int compareTo(Participant o) {
        if (this.score == o.score) {
            return this.name.compareTo(o.name);
        }
        return o.score - this.score;
    }
}

public class Main {

    static String rank(Participant[] participants) {
        StringBuilder sb = new StringBuilder();
        int rank = 1;
        Arrays.sort(participants);
        int prevScore = participants[0].score;
        for (int i = 0; i < participants.length; i++) {
            if (prevScore != participants[i].score) {
                rank = i + 1;
            }
            if (!participants[i].isHidden) {
                sb.append(rank).append(" ").append(participants[i].name).append(" ").append(participants[i].score).append("\n");
            }
            prevScore = participants[i].score;
        }
        return sb.toString();
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        Participant[] participants = new Participant[N];
        for (int i = 0; i < N; i++) {
            participants[i] = new Participant(br.readLine());
        }
        bw.write(rank(participants));
        br.close();
        bw.flush();
        bw.close();
    }
}