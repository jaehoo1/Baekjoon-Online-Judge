import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int Q = Integer.parseInt(st.nextToken());
        List<Integer> notes = new ArrayList<>();
        for (int i = 1; i <= N; i++) {
            notes.addAll(Collections.nCopies(Integer.parseInt(br.readLine()), i));
        }
        while (Q-- > 0) {
            bw.write(notes.get(Integer.parseInt(br.readLine())) + "\n");
        }
        br.close();
        bw.flush();
        bw.close();
    }
}