import java.util.*;

public class Main {

    static List<int[]> combinations = new ArrayList<>();
    static String[] words = new String[6];
    static Map<String, Integer> wordsCount = new HashMap<>();

    static void backtracking(int[] arr, int depth, int idx) {

        if (idx == 6) {
            return;
        }
        arr[depth] = idx;
        if (depth == 2) {
            combinations.add(Arrays.copyOf(arr, 3));
            return;
        }
        for (int i = 0; i < 6; i++) {
            backtracking(arr, depth + 1, i);
        }
    }

    static void makeCombinations() {

        for (int i = 0; i < 6; i++) {
            backtracking(new int[3], 0, i);
        }
    }

    static String[] makePuzzleByCombination(int[] combination) {

        String[] puzzle = new String[3];
        for (int i = 0; i < 3; i++) {
            puzzle[i] = words[combination[i]];
        }
        return puzzle;
    }

    static String[] wordsInPuzzle(String[] puzzle) {

        String[] words = new String[6];
        for (int i = 0; i < 3; i++) {
            StringBuilder row = new StringBuilder();
            StringBuilder col = new StringBuilder();
            for (int j = 0; j < 3; j++) {
                row.append(puzzle[i].charAt(j));
                col.append(puzzle[j].charAt(i));
            }
            words[i * 2] = row.toString();
            words[i * 2 + 1] = col.toString();
        }
        return words;
    }

    static boolean isValidPuzzle(String[] puzzle) {

        Map<String, Integer> counts = new HashMap<>();
        for (String word : wordsInPuzzle(puzzle)) {
            counts.merge(word, 1, Integer::sum);
        }

        for (String word : wordsCount.keySet()) {
            if (wordsCount.get(word) != counts.get(word)) {
                return false;
            }
        }
        return true;
    }

    static boolean isValidPuzzle(int[] combination) {

        return isValidPuzzle(makePuzzleByCombination(combination));
    }

    public static void main(String[] args) {

        makeCombinations();
        Scanner sc = new Scanner(System.in);
        for (int i = 0; i < 6; i++) {
            words[i] = sc.next();
            wordsCount.merge(words[i], 1, Integer::sum);
        }
        for (int[] combination : combinations) {
            if (isValidPuzzle(combination)) {
                String[] result = makePuzzleByCombination(combination);
                for (int i = 0; i < 3; i++) {
                    System.out.println(result[i]);
                }
                System.exit(0);
            }
        }
        System.out.println(0);
    }
}