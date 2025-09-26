import java.io.*;
import java.util.*;

class Team {

    String name;
    int solved, penalty;

    public Team(String name, int solved, int penalty) {
        this.name = name;
        this.solved = solved;
        this.penalty = penalty;
    }
}

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        Map<String, Team> map = new HashMap<>();
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            String univ = st.nextToken();
            String teamName = st.nextToken();
            int solved = Integer.parseInt(st.nextToken());
            int penalty = Integer.parseInt(st.nextToken());
            map.compute(univ, (k, v) -> {
                if (v == null) {
                    return new Team(teamName, solved, penalty);
                }
                if (v.solved < solved) {
                    return new Team(teamName, solved, penalty);
                } else if (v.solved > solved) {
                    return v;
                }
                return v.penalty < penalty ? v : new Team(teamName, solved, penalty);
            });
        }
        List<Team> teams = new ArrayList<>(map.values());
        teams.sort((t1, t2) -> {
            if (t1.solved == t2.solved) {
                return t1.penalty - t2.penalty;
            }
            return t2.solved - t1.solved;
        });
        for (int i = 0; i < K; i++) {
            bw.write(teams.get(i).name + "\n");
        }
        br.close();
        bw.flush();
        bw.close();
    }
}