import java.util.Scanner;
import java.math.BigInteger;

class Main {
    public static void main(String[] args) {
        BigInteger[] fibs = new BigInteger[1005];
        fibs[0] = BigInteger.valueOf(1);
        fibs[1] = BigInteger.valueOf(2);
        for (int i = 2; i < 1005; i++)
            fibs[i] = fibs[i - 2].add(fibs[i - 1]);

        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            int n = sc.nextInt();
            System.out.println(fibs[n]);
        }
    }
}
