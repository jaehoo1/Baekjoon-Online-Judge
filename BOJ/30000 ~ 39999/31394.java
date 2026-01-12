import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[] marks = new int[n];
        for (int i = 0; i < n; i++) {
            marks[i] = Integer.parseInt(br.readLine());
        }
        String result;
        if (Arrays.stream(marks).anyMatch(i -> i == 3)) {
            result = "None";
        } else if (Arrays.stream(marks).allMatch(i -> i == 5)) {
            result = "Named";
        } else if (Arrays.stream(marks).average().getAsDouble() >= 4.5) {
            result = "High";
        } else {
            result = "Common";
        }
        System.out.println(result);
    }
}