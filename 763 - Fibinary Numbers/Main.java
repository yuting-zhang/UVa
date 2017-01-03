import java.util.Scanner;
import java.math.BigInteger;
import java.util.Arrays;

class Main {
    public static BigInteger[] generateFibSeq() {
        BigInteger[] fibs = new BigInteger[105];
        fibs[0] = BigInteger.valueOf(1);
        fibs[1] = BigInteger.valueOf(2);
        for (int i = 2; i < 105; i++)
            fibs[i] = fibs[i - 1].add(fibs[i - 2]);
        return fibs;
    }

    public static BigInteger fibStringToInt(String num, BigInteger[] fibs) {
        BigInteger value = BigInteger.ZERO;
        for (int i = 0; i < num.length(); i++) {
            if (num.charAt(i) == '1') {
                value = value.add(fibs[num.length() - 1 - i]);
            }
        }
        return value;
    }

    public static String IntToFibString(BigInteger num, BigInteger[] fibs) {
        StringBuilder value = new StringBuilder();
        int index = Arrays.binarySearch(fibs, num);
        if (index < 0)
            index = -index - 2;

        for (int i = index; i >= 0; i--) {
            if (fibs[i].compareTo(num) <= 0) {
                value = value.append('1');
                num = num.subtract(fibs[i]);
            }
            else 
                value = value.append('0');
        }
        if (value.length() == 0)
            value.append('0');
        return value.toString();
    }

    public static void main(String[] args) {
        BigInteger[] fibs = generateFibSeq();
        Scanner sc = new Scanner(System.in);

        boolean firstCase = true;

        while (sc.hasNext()) {
            if (firstCase)
                firstCase = false;
            else
                System.out.println();
            BigInteger num1 = fibStringToInt(sc.next(), fibs);
            BigInteger num2 = fibStringToInt(sc.next(), fibs);
            System.out.println(IntToFibString(num1.add(num2), fibs));
        }
    }
}
