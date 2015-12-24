import java.util.GregorianCalendar;
import java.util.Scanner;
import java.util.Calendar;

class Main {
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();
		scanner.nextLine();
		for (int case_no = 1; case_no <= N; case_no++){
			String line;
			line = scanner.nextLine();
			int month = Integer.parseInt(line.substring(0, 2)),
				date = Integer.parseInt(line.substring(2, 4)),
				year = Integer.parseInt(line.substring(4, 8));
			Calendar calendar = new GregorianCalendar(year, month - 1, date);
			
			calendar.add(Calendar.WEEK_OF_MONTH, 40);
			
			month = calendar.get(Calendar.MONTH);
			month++;
			String month_s = String.valueOf(month);
			if (month_s.length() == 1)
				month_s = "0" + month_s;
			
			date = calendar.get(Calendar.DATE);
			String date_s = String.valueOf(date);
			if (date_s.length() == 1)
				date_s = "0" + date_s;
			
			year = calendar.get(Calendar.YEAR);
			String year_s = String.valueOf(year);
			while (year_s.length() < 4)
				year_s = "0" + year_s;
			
			
			String sign = "";
			if (month == 1 && date >= 21)
				sign = "aquarius";
			if (month == 2 && date <= 19)
				sign = "aquarius";
			if (month == 2 && date >= 20)
				sign = "pisces";
			if (month == 3 && date <= 20)
				sign = "pisces";
			if (month == 3 && date >= 21)
				sign = "aries";
			if (month == 4 && date <= 20)
				sign = "aries";
			if (month == 4 && date >= 21)
				sign = "taurus";
			if (month == 5 && date <= 21)
				sign = "taurus";
			if (month == 5 && date >= 22)
				sign = "gemini";
			if (month == 6 && date <= 21)
				sign = "gemini";
			if (month == 6 && date >= 22)
				sign = "cancer";
			if (month == 7 && date <= 22)
				sign = "cancer";
			if (month == 7 && date >= 23)
				sign = "leo";
			if (month == 8 && date <= 21)
				sign = "leo";
			if (month == 8 && date >= 22)
				sign = "virgo";
			if (month == 9 && date <= 23)
				sign = "virgo";
			if (month == 9 && date >= 24)
				sign = "libra";
			if (month == 10 && date <= 23)
				sign = "libra";
			if (month == 10 && date >= 24)
				sign = "scorpio";
			if (month == 11 && date <= 22)
				sign = "scorpio";
			if (month == 11 && date >= 23)
				sign = "sagittarius";
			if (month == 12 && date <= 22)
				sign = "sagittarius";
			if (month == 12 && date >= 23)
				sign = "capricorn";
			if (month == 1 && date <= 20)
				sign = "capricorn";
			System.out.printf("%d %s/%s/%s %s\n", case_no, month_s, date_s, year_s, sign);
				
		}
	}
}
