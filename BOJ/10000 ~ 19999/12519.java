import java.io.*;
import java.util.*;

public class Main {

    static Set<String> makeSubstrings(String song) {
        Set<String> set = new HashSet<>();
        for (int i = 0; i < song.length(); i++) {
            for (int j = i + 1; j < song.length() + 1; j++) {
                set.add(song.substring(i, j));
            }
        }
        return set;
    }

    static String findUniqueSubstring(String song, List<String> songs, SortedSet<String> substrings) {
        if (songs.size() == 1) {
            return "\"\"";
        }
        for (String sub : substrings) {
            if (!song.contains(sub)) {
                continue;
            }
            boolean otherMatch = false;
            for (String otherSong : songs) {
                if (song.equals(otherSong)) {
                    continue;
                }
                if (otherSong.contains(sub)) {
                    otherMatch = true;
                    break;
                }
            }
            if (!otherMatch) {
                return "\"" + sub + "\"";
            }
        }
        return ":(";
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());
        for (int t = 1; t <= T; t++) {
            bw.write("Case #" + t +  ":\n");
            List<String> songNames = new ArrayList<>();
            SortedSet<String> substrings = new TreeSet<>((o1, o2) -> {
                if (o1.length() == o2.length()) {
                    return o1.compareTo(o2);
                }
                return o1.length() - o2.length();
            });
            int N = Integer.parseInt(br.readLine());
            for (int i = 0; i < N; i++) {
                songNames.add(br.readLine().toUpperCase());
                substrings.addAll(makeSubstrings(songNames.get(i)));
            }
            for (int i = 0; i < N; i++) {
                bw.write(findUniqueSubstring(songNames.get(i), songNames, substrings) + "\n");
            }
        }
        br.close();
        bw.flush();
        bw.close();
    }
}