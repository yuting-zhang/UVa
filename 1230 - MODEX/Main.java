import java.util.Scanner;
import java.math.BigInteger;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int c = sc.nextInt();
        for (int cases = 0; cases < c; cases++) {
            BigInteger x, y, n;
            x = sc.nextBigInteger();
            y = sc.nextBigInteger();
            n = sc.nextBigInteger();
            System.out.println(x.modPow(y, n));
        }
        c = sc.nextInt();
    }
}
