import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int findValidIndex(int[] arr) {
        for (int i = 0; i < 3; i++) {
            if (arr[i] != -1 && arr[i + 1] != -1) {
                return i;
            }
        }
        return -1;
    }

    static int findMissingIndex(int[] arr) {
        for (int i = 0; i < 4; i++) {
            if (arr[i] == -1) {
                return i;
            }
        }
        return -1;
    }

    static boolean isArithmeticSequence(int[] sequence) {
        int[] copied = Arrays.copyOf(sequence, 4);
        int validIndex = findValidIndex(copied);
        int diff = copied[validIndex + 1] - copied[validIndex];
        int missingIndex = findMissingIndex(copied);
        copied[missingIndex] = missingIndex == 0
                ? copied[missingIndex + 1] - diff
                : copied[missingIndex - 1] + diff;
        if (copied[missingIndex] < 1 || copied[missingIndex] > 10000) {
            return false;
        }
        for (int i = 0; i < 3; i++) {
            if (copied[i] + diff != copied[i + 1]) {
                return false;
            }
        }
        System.arraycopy(copied, 0, sequence, 0, 4);
        return true;
    }

    static boolean isGeometricSequence(int[] sequence) {
        int[] copied = Arrays.copyOf(sequence, 4);
        int validIndex = findValidIndex(sequence);
        int ratio = copied[validIndex + 1] / copied[validIndex];
        int missingIndex = findMissingIndex(copied);
        copied[missingIndex] = missingIndex == 0
                ? copied[missingIndex + 1] / ratio
                : copied[missingIndex - 1] * ratio;
        if (copied[missingIndex] < 1 || copied[missingIndex] > 10000) {
            return false;
        }
        for (int i = 0; i < 3; i++) {
            if (copied[i] * ratio != copied[i + 1]) {
                return false;
            }
        }
        System.arraycopy(copied, 0, sequence, 0, 4);
        return true;
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int[] ints = new int[4];
        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 0; i < 4; i++) {
                ints[i] = Integer.parseInt(st.nextToken());
            }
            if (Arrays.stream(ints).allMatch(i -> i == -1)) {
                break;
            }
            int missingIndex = findMissingIndex(ints);
            bw.write(isArithmeticSequence(ints) || isGeometricSequence(ints) ? ints[missingIndex] + "\n" : "-1\n");
        }
        br.close();
        bw.flush();
        bw.close();
    }
}