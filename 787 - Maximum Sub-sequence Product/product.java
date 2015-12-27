import java.util.Scanner;
import java.math.BigInteger;
import java.util.Vector;

class Main{
    static Vector<BigInteger> seq;
    static Vector<BigInteger> prod;

    public static BigInteger processData(int begin, int end){
        BigInteger retval = BigInteger.valueOf(-999999);

        for (int i = begin; i <= end; i++)
            for (int j = i; j <= end; j++){
                BigInteger product = prod.elementAt(j).divide(prod.elementAt(i - 1));
                if (product.compareTo(retval) == 1)
                    retval = product;
            }
        return retval;
    }

    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNextBigInteger()){
            seq = new Vector<BigInteger>();
            prod = new Vector<BigInteger>();
            prod.add(BigInteger.ONE);

            while (true){
                BigInteger data = scanner.nextBigInteger();
                if (data.equals(BigInteger.valueOf(-999999)))
                    break;
                seq.add(data);
                prod.add(BigInteger.ONE);
            }

            BigInteger answer = seq.elementAt(0);
            int begin = 1, end = 0;

            for (int i = 0; i < seq.size(); i++){
                if (!seq.elementAt(i).equals(BigInteger.ZERO)){
                    prod.set(i + 1, seq.elementAt(i).multiply(prod.elementAt(i)));
                    end = i + 1;
                }
                else{
                    BigInteger local = processData(begin, end);
                    if (local.compareTo(answer) == 1)
                        answer = local;
                    if (BigInteger.ZERO.compareTo(answer) == 1)
                        answer = BigInteger.ZERO;

                    begin = i + 2;
                    prod.set(i + 1, BigInteger.ONE);
                }
             
            }
            BigInteger local = processData(begin, end);
            if (local.compareTo(answer) == 1)
                answer = local;
            System.out.println(answer);
        }
    }
}
