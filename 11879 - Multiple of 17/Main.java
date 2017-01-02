import java.util.Scanner;
import java.math.BigInteger;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BigInteger n;
        while (true) {
            n = sc.nextBigInteger();
            if (n.compareTo(BigInteger.ZERO) == 0)
                break;
            int lastDigit = n.remainder(BigInteger.valueOf(10)).intValue();
            n = n.divide(BigInteger.valueOf(10));
            n = n.subtract(BigInteger.valueOf(lastDigit * 5));
            if (n.remainder(BigInteger.valueOf(17)).intValue() == 0)
                System.out.println(1);
            else
                System.out.println(0);
        }
    }
}
