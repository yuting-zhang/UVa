import java.util.Scanner;
import java.math.BigInteger;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BigInteger[] Cat = new BigInteger[30];
        BigInteger[] S = new BigInteger[30];

        Cat[0] = BigInteger.valueOf(1);
        for (int i = 0; i < 29; i++) 
            Cat[i + 1] = BigInteger.valueOf((2 * i + 2) * (2 * i + 1)).multiply
                (Cat[i]).divide(BigInteger.valueOf(i + 2)).divide
                (BigInteger.valueOf(i + 1));

        S[1] = BigInteger.valueOf(1);
        S[2] = BigInteger.valueOf(1);
        for (int i = 3; i < 30; i++)
            S[i] = (S[i - 1].multiply(BigInteger.valueOf(6 * i - 9)).subtract 
                 (S[i - 2].multiply(BigInteger.valueOf(i - 3))).divide
                 (BigInteger.valueOf(i)));

        while (sc.hasNext()) {
            int n = sc.nextInt();
            System.out.println(S[n].subtract(Cat[n - 1]));
        }
    }
}
