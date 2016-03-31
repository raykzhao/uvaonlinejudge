import java.util.*;

class Main
{
	public static void main(String args[])
	{
		 final String signName[] = {
			"capricorn",
			"aquarius",
			"pisces",
			"aries",
			"taurus",
			"gemini",
			"cancer",
			"leo",
			"virgo",
			"libra",
			"scorpio",
			"sagittarius"};

		final int signDif[][] = {
			{Calendar.JANUARY, 20},
			{Calendar.FEBRUARY, 19},
			{Calendar.MARCH, 20},
			{Calendar.APRIL, 20},
			{Calendar.MAY, 21},
			{Calendar.JUNE, 21},
			{Calendar.JULY, 22},
			{Calendar.AUGUST, 21},
			{Calendar.SEPTEMBER, 23},
			{Calendar.OCTOBER, 23},
			{Calendar.NOVEMBER, 22},
			{Calendar.DECEMBER, 22}};

		Scanner console = new Scanner(System.in);

		int numCase = console.nextInt();

		for (int cas = 1; cas <= numCase; cas++)
		{
			String startDate = console.next();
			GregorianCalendar cal = new GregorianCalendar(
					Integer.parseInt(startDate.substring(4, 8)),
					Integer.parseInt(startDate.substring(0, 2)) - 1,
					Integer.parseInt(startDate.substring(2, 4)));

			cal.add(Calendar.WEEK_OF_YEAR, 40);
			
			int i = 0;

			for (i = 0; i < 12; i++)
			{
				GregorianCalendar sign = new GregorianCalendar(
						cal.get(Calendar.YEAR),
						signDif[i][0],
						signDif[i][1]);

				if (cal.compareTo(sign) <= 0)
				{
					break;
				}
			}

			if (i == 12)
			{
				i = 0;
			}

			System.out.printf("%d %02d/%02d/%04d ", cas, cal.get(Calendar.MONTH) + 1, cal.get(Calendar.DAY_OF_MONTH), cal.get(Calendar.YEAR));
			System.out.println(signName[i]);
		}
	}
}

