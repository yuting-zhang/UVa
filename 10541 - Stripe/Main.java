import java.util.Scanner;
import java.math.BigInteger;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();

        for (int cases = 0; cases < T; cases++) {
            int N = sc.nextInt();
            int K = sc.nextInt();
            for (int i = 0; i < K; i++) {
                int num = sc.nextInt();
                N -= num;
            }

            if (N < K - 1) {
                System.out.println("0");
                continue;
            }
                
            N++;

            if (K > (N - K))
                K = N - K;

            BigInteger result = BigInteger.ONE;
            for (int i = N; i > N - K; i--)
                result = result.multiply(BigInteger.valueOf(i));
            for (int i = K; i > 1; i--)
                result = result.divide(BigInteger.valueOf(i));
            System.out.println(result);
        }
    }
}
