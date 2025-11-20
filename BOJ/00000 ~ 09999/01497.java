import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.stream.IntStream;

public class Main {

    static int N, M;
    static int maxAvailableSongs, minGuitarCount = Integer.MAX_VALUE;

    static String[] guitarsAvailableSongs;
    static boolean[] visited;

    static String importGuitar(String availableSongs, String guitarSongs) {
        char[] chars = availableSongs.toCharArray();
        for (int i = 0; i < M; i++) {
            if (guitarSongs.charAt(i) == 'Y') {
                chars[i] = 'Y';
            }
        }
        return new String(chars);
    }

    static String importGuitar(String availableSongs, int guitarIdx) {
        return importGuitar(availableSongs, guitarsAvailableSongs[guitarIdx]);
    }

    static int availableSongsCount(String availableSongs) {
        return IntStream.range(0, M)
                .map((i) -> availableSongs.charAt(i) == 'Y' ? 1 : 0)
                .sum();
    }

    static void chooseGuitar(int depth, String availableSongs) {
        int curAvailableSongsCount = availableSongsCount(availableSongs);
        if (curAvailableSongsCount > maxAvailableSongs) {
            maxAvailableSongs = curAvailableSongsCount;
            minGuitarCount = depth;
        } else if (curAvailableSongsCount == maxAvailableSongs) {
            minGuitarCount = Math.min(minGuitarCount, depth);
        }
        if (depth == N || curAvailableSongsCount == M) {
            return;
        }
        for (int i = depth; i < N; i++) {
            if (visited[i]) {
                continue;
            }
            visited[i] = true;
            chooseGuitar(depth + 1, importGuitar(availableSongs, i));
            visited[i] = false;
        }
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        guitarsAvailableSongs = new String[N];
        visited = new boolean[N];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            st.nextToken();
            guitarsAvailableSongs[i] = st.nextToken();
        }
        chooseGuitar(0, "N".repeat(M));
        System.out.println(maxAvailableSongs == 0 ? -1 : minGuitarCount);
    }
}