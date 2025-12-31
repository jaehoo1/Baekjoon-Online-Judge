import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.util.stream.Collectors;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        List<Integer> gis = new ArrayList<>();
        gis.add(Integer.valueOf(st.nextToken()));
        for (int i = 1; i < N; i++) {
            int num = Integer.parseInt(st.nextToken());
            if (num > gis.get(gis.size() - 1)) {
                gis.add(num);
            }
        }
        bw.write(gis.size() + "\n");
        bw.write(gis.stream()
                .map(String::valueOf)
                .collect(Collectors.joining(" ")));
        br.close();
        bw.flush();
        bw.close();
    }
}