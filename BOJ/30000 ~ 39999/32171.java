import java.util.Scanner;

class Fence {

    int down, left, up, right;

    public Fence(int down, int left, int up, int right) {
        this.down = down;
        this.left = left;
        this.up = up;
        this.right = right;
    }

    void update(int down, int left, int up, int right) {
        this.down = Math.min(this.down, down);
        this.left = Math.min(this.left, left);
        this.up = Math.max(this.up, up);
        this.right = Math.max(this.right, right);
    }

    int cost() {
        return (up - down) * 2 + (right - left) * 2;
    }
}

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        Fence fence = new Fence(sc.nextInt(), sc.nextInt(), sc.nextInt(), sc.nextInt());
        System.out.println(fence.cost());
        while (N-- > 1) {
            fence.update(sc.nextInt(), sc.nextInt(), sc.nextInt(), sc.nextInt());
            System.out.println(fence.cost());
        }
    }
}