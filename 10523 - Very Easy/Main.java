import java.util.Scanner;
import java.math.BigInteger;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            int N = sc.nextInt();
            BigInteger A = sc.nextBigInteger();

            BigInteger sum = BigInteger.ZERO;
            for (int i = 1; i <= N; i++) {
                sum = sum.add(A.pow(i).multiply(BigInteger.valueOf(i)));
            }
            System.out.println(sum.toString());
        }
    }
}
