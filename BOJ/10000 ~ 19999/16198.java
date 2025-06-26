import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class Main {

    static int max = 0;

    static void backtracking(List<Integer> list, int energy) {

        if (list.size() == 2) {
            max = Math.max(max, energy);
            return;
        }
        for (int i = 1; i < list.size() - 1; i++) {
            int addingEnergy = list.get(i - 1) * list.get(i + 1);
            List<Integer> copied = new ArrayList<>(List.copyOf(list));
            copied.remove(i);
            backtracking(copied, energy + addingEnergy);
        }
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        List<Integer> W = new LinkedList<>();
        for (int i = 0; i < N; i++) {
            W.add(sc.nextInt());
        }
        backtracking(W, 0);
        System.out.println(max);
    }
}