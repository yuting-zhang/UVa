import java.util.Scanner;
import java.math.BigInteger;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            int base = sc.nextInt();
            if (base == 0)
                break;

            BigInteger p = new BigInteger(sc.next(), base);
            BigInteger m = new BigInteger(sc.next(), base);
            System.out.println(p.mod(m).toString(base)); 
        }
    }
}
