import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Pizza {

    int calories;
    String name;
    boolean vetoed;

    public Pizza(int calories, String name) {
        this.calories = calories;
        this.name = name;
        this.vetoed = false;
    }
}

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int p = Integer.parseInt(st.nextToken()) - 1;
        int alice = n - 1, bob = 0;
        Pizza[] pizzas = new Pizza[n];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            pizzas[i] = new Pizza(Integer.parseInt(st.nextToken()), st.nextToken());
        }
        for (int i = 0; i < n - 1; i++) {
            if (i % 3 == 0) {
                pizzas[alice--].vetoed = true;
            } else if (i % 3 == 1) {
                pizzas[bob++].vetoed = true;
            } else {
                pizzas[alice - p > p - bob ? alice-- : bob++].vetoed = true;
            }
        }
        System.out.println(pizzas[p].vetoed ? "NO" : "YES");
    }
}