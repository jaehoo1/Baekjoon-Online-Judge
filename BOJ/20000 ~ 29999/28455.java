import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.stream.Collectors;

public class Main {

    static int abilityScore(int level) {
        int ability = 0;
        if (level >= 60) {
            ability++;
        }
        if (level >= 100) {
            ability++;
        }
        if (level >= 140) {
            ability++;
        }
        if (level >= 200) {
            ability++;
        }
        if (level >= 250) {
            ability++;
        }
        return ability;
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        List<Integer> levels = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            levels.add(Integer.valueOf(br.readLine()));
        }
        levels = levels.stream()
                .sorted(Collections.reverseOrder())
                .limit(42)
                .collect(Collectors.toList());
        int sum = levels.stream()
                .mapToInt(Integer::intValue)
                .sum();
        int abilityScore = levels.stream()
                .mapToInt(Main::abilityScore)
                .sum();
        System.out.println(sum + " " + abilityScore);
    }
}