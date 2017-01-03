import java.util.Scanner;
import java.math.BigDecimal;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for (int cases = 0; cases < n; cases++) {
            BigDecimal sum = BigDecimal.ZERO;
            while (true) {
                BigDecimal num = sc.nextBigDecimal();
                if (num.compareTo(BigDecimal.ZERO) == 0)
                    break;
                sum = sum.add(num);
            }
            System.out.println(sum.stripTrailingZeros().toPlainString());
        }
    }
}
