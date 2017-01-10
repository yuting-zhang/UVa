import java.util.Scanner;
import java.math.BigInteger;

class Main {
    public static void main(String[] args) {
        String[] factorial = new String[367]; 
        factorial[0] = "1";
        BigInteger fact = BigInteger.ONE;
        for (int i = 1; i <= 366; i++) {
            fact = fact.multiply(BigInteger.valueOf(i));
            factorial[i] = fact.toString();
        }

        int N;
        Scanner sc = new Scanner(System.in);
        while (true) {
            N = sc.nextInt();
            if (N == 0)
                break;

            int[] digits = new int[10];

            for (char digit : factorial[N].toCharArray())
                digits[digit - '0']++;
            System.out.printf("%d! --\n", N);
            for (int i = 0; i < 10; i++) {
                if (i % 5 != 0)
                    System.out.printf(" ");
                System.out.printf("   (%d)%5d", i, digits[i]);
                if (i % 5 == 4)
                    System.out.println();
            }
        }
    }
}
