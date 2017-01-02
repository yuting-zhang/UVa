import java.util.Scanner;
import java.math.BigInteger;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String num1, num2;
        while (sc.hasNext()) {
            num1 = sc.next();
            num2 = sc.next();
            int base1 = -1, base2 = -1;
            boolean done = false;

            for (int i = 2; i <= 36 && !done; i++)
                for (int j = 2; j <= 36 && !done; j++) {
                    try {
                        BigInteger int1 = new BigInteger(num1, i);
                        BigInteger int2 = new BigInteger(num2, j);
                        if (int1.compareTo(int2) == 0) {
                            base1 = i;
                            base2 = j;
                            done = true;
                        }
                    }
                    catch (NumberFormatException ex){
                        continue;
                    }
                }
            
            if (base1 != -1) {
                System.out.printf("%s (base %d) = %s (base %d)\n",
                                  num1, base1, num2, base2);
            }
            else {
                System.out.printf("%s is not equal to %s in any base 2..36\n",
                                  num1, num2);
            }
        }
    }
}
