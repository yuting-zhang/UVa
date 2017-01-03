import java.util.Scanner;
import java.math.BigInteger;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        for (int cases = 0; cases < N; cases++) {
            BigInteger p = sc.nextBigInteger();
            String garbage = sc.next();
            BigInteger q = sc.nextBigInteger();

            BigInteger gcd = p.gcd(q);
            p = p.divide(gcd);
            q = q.divide(gcd);
            System.out.println(p + " / " + q);
        }
    }
}
