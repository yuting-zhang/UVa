import java.util.Scanner;
import java.math.BigInteger;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        for (int cases = 0; cases < N; cases++) {
            StringBuilder builder = new StringBuilder(sc.next());
            BigInteger num1 = new BigInteger(builder.reverse().toString());

            builder = new StringBuilder(sc.next());
            BigInteger num2 = new BigInteger(builder.reverse().toString());

            builder = new StringBuilder(num1.add(num2).toString());
            builder = builder.reverse();

            while (builder.charAt(0) == '0' && builder.length() > 1)
                builder.deleteCharAt(0);
            System.out.println(builder.toString());
        }
    }
}
