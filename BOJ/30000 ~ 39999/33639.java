import java.io.*;
import java.util.*;

public class Main {

    static String initial(String firstName, String lastName) {
        return firstName.substring(0, 1) + lastName.substring(0, 1);
    }

    static String initial(String name) {
        StringTokenizer st = new StringTokenizer(name);
        return initial(st.nextToken(), st.nextToken());
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        Map<String, List<String>> initials = new HashMap<>();
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int Q = Integer.parseInt(st.nextToken());
        while (N-- > 0) {
            String name = br.readLine();
            String initial = initial(name);
            initials.computeIfAbsent(initial, k -> new ArrayList<>())
                    .add(name);
        }
        while (Q-- > 0) {
            List<String> result = initials.get(br.readLine());
            if (result == null) {
                bw.write("nobody\n");
            } else if (result.size() > 1) {
                bw.write("ambiguous\n");
            } else {
                bw.write(result.get(0) + "\n");
            }
        }
        br.close();
        bw.flush();
        bw.close();
    }
}