import java.util.Scanner;
import java.math.BigInteger;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (true) {
            BigInteger p = sc.nextBigInteger();
            BigInteger a = sc.nextBigInteger();
            if (p.compareTo(BigInteger.ZERO) == 0)
                break;

            if (!p.isProbablePrime(10) && a.modPow(p, p).compareTo(a) == 0)
                System.out.println("yes");
            else
                System.out.println("no");
        }
    }
}
