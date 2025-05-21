import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        for (int t = 1; t <= n; t++) {
            String url = br.readLine();
            String protocol = url.substring(0, url.indexOf("://"));
            url = url.substring(url.indexOf("://") + 3);
            String host = "";
            String port = "";
            String path = "";
            if (url.contains(":") && url.contains("/")) {
                host = url.substring(0, Math.min(url.indexOf(':'), url.indexOf('/')));
                port = url.indexOf(':') < url.indexOf('/') ? url.substring(url.indexOf(':') + 1, url.indexOf('/')) : "";
                path = url.substring(url.indexOf('/') + 1);
            } else if (url.contains(":")) {
                host = url.substring(0, url.indexOf(':'));
                port = url.substring(url.indexOf(':') + 1);
            } else if (url.contains("/")) {
                host = url.substring(0, url.indexOf('/'));
                path = url.substring(url.indexOf('/') + 1);
            } else {
                host = url;
            }
            bw.write("URL #" + t + "\n");
            bw.write("Protocol = " + protocol + "\n");
            bw.write("Host     = " + host + "\n");
            bw.write("Port     = " + (port.isEmpty() ? "<default>" : port) + "\n");
            bw.write("Path     = " + (path.isEmpty() ? "<default>" : path) + "\n");
            bw.write("\n");
        }
        br.close();
        bw.flush();
        bw.close();
    }
}