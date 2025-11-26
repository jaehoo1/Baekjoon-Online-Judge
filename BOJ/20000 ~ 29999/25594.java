import java.io.*;

public class Main {

    static final char[][] HG = {"aespa".toCharArray(), "baekjoon".toCharArray(), "cau".toCharArray(), "debug".toCharArray(), "edge".toCharArray(), "firefox".toCharArray(), "golang".toCharArray(), "haegang".toCharArray(), "iu".toCharArray(), "java".toCharArray(), "kotlin".toCharArray(), "lol".toCharArray(), "mips".toCharArray(), "null".toCharArray(), "os".toCharArray(), "python".toCharArray(), "query".toCharArray(), "roka".toCharArray(), "solvedac".toCharArray(), "tod".toCharArray(), "unix".toCharArray(), "virus".toCharArray(), "whale".toCharArray(), "xcode".toCharArray(), "yahoo".toCharArray(), "zebra".toCharArray()};

    static boolean find(char[] src, int idx, char[] find) {
        if (src.length - idx < find.length) {
            return false;
        }
        for (int i = 0; i < src.length && i < find.length; i++) {
            if (src[idx + i] != find[i]) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) throws IOException {

        char[] S = new BufferedReader(new InputStreamReader(System.in)).readLine().toCharArray();
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int idx = 0;
        StringBuilder sb = new StringBuilder();
        while (idx < S.length) {
            int hgIdx = S[idx] - 'a';
            if (!find(S, idx, HG[hgIdx])) {
                break;
            }
            sb.append(S[idx]);
            idx += HG[hgIdx].length;
        }
        if (idx == S.length) {
            bw.write("It's HG!\n");
            bw.write(sb.toString());
        } else {
            bw.write("ERROR!");
        }
        bw.flush();
        bw.close();
    }
}