import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        int[][] arr = {
                {200, 210, 220},
                {210, 220, 225},
                {220, 225, 230},
                {225, 230, 235},
                {230, 235, 245},
                {235, 245, 250},

                {260, 265, 270},
                {265, 270, 275},
                {270, 275, 280},
                {275, 280, 285},
                {280, 285, 290},
                {285, 290, 295},
                {290, 295, 300}
        };

        Scanner sc = new Scanner(System.in);
        int L = sc.nextInt();

        for (int i = 0; i < 6; i++) {
            System.out.print((L < arr[i][0] ? 0 : L < arr[i][1] ? 500 : L < arr[i][2] ? 300 : 100) + " ");
        }
        System.out.println();
        for (int i = 6; i < 13; i++) {
            System.out.print((L < arr[i][0] ? 0 : L < arr[i][1] ? 500 : L < arr[i][2] ? 300 : 100) + " ");
        }
    }
}