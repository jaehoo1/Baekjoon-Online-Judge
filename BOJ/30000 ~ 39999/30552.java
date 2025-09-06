import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        String[] names = new String[N];
        boolean absence = false;

        for (int i = 0; i < N; i++) {
            names[i] = br.readLine();
        }
        for (int i = 0; i < N; i++) {
            if (!names[i].equals("Present!") && (i + 1 >= N || !names[i + 1].equals("Present!"))) {
                bw.write(names[i] + "\n");
                absence = true;
            }
        }
        if (!absence) {
            bw.write("No Absences");
        }
        br.close();
        bw.flush();
        bw.close();
    }
}