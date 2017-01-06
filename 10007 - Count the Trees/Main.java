import java.util.Scanner;
import java.math.BigInteger;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (sc.hasNext()) {
            int n = sc.nextInt();
            if (n == 0)
                break;
            BigInteger result = BigInteger.ONE;

            for (int i = 2 * n; i > n; i--)
                result = result.multiply(BigInteger.valueOf(i));
            result = result.divide(BigInteger.valueOf(n + 1));
            System.out.println(result);
        }
    }
}
