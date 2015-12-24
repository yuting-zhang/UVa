import java.util.Calendar;
import java.util.GregorianCalendar;
import java.util.Scanner;

class Main {
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
		int N, Y, M, D;
		while (true){
			N = scanner.nextInt();
			D = scanner.nextInt();
			M = scanner.nextInt();
			Y = scanner.nextInt();
			if (N == 0 && D == 0 && M == 0 && Y == 0)
				break;
			
			Calendar calendar = new GregorianCalendar(Y, M - 1, D);
			calendar.add(Calendar.DATE, N);
			System.out.printf("%d %d %d\n", calendar.get(Calendar.DATE),
											calendar.get(Calendar.MONTH) + 1,
											calendar.get(Calendar.YEAR));
		}
	}
}
