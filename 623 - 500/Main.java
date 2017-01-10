import java.util.Scanner;
import java.math.BigInteger;

class Main {
    public static void main(String[] args) {
        String[] factorial = new String[1001];
        factorial[0] = "1";
        BigInteger fact = BigInteger.ONE;

        for (int i = 1; i <= 1000; i++) {
            fact = fact.multiply(BigInteger.valueOf(i));
            factorial[i] = fact.toString();
        }

        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            int n = sc.nextInt();
            System.out.println(n + "!");
            System.out.println(factorial[n]);
        }
    }
}
