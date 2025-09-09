import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int support = Integer.parseInt(br.readLine());
        List<Integer> votes = new ArrayList<>(n);
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n - 1; i++) {
            votes.add(Integer.valueOf(st.nextToken()));
        }
        votes.add(support);
        Collections.sort(votes);
        Collections.reverse(votes);
        System.out.println(votes.indexOf(support) + 1);
    }
}