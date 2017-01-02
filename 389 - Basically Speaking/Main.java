import java.util.Scanner;
import java.math.BigInteger;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            String number = sc.next();
            int fromBase = sc.nextInt();
            int toBase = sc.nextInt();
            number = new BigInteger(number, fromBase).toString(toBase);
            number = number.toUpperCase();
            if (number.length() > 7)
                number = "ERROR";
            System.out.printf("%7s\n", number);
        }
    }
}
