import java.util.*;

class Main
{
	public static void main(String args[])
	{
		final String splitRegex = "\\+|\\-|\\=";

		Scanner console = new Scanner(System.in);

		int correctNumber = 0;

		while (console.hasNext())
		{
			String formula = console.nextLine();

			if (formula.indexOf('?') != -1)
			{
				continue;
			}

			boolean plusSign = true;

			if (formula.indexOf('+') >= 0)
			{
				plusSign = true;
			}
			else if (formula.indexOf('-') >= 0)
			{
				plusSign = false;
			}

			String token[] = formula.split(splitRegex);

			Integer op1 = Integer.valueOf(token[0]);
			Integer op2 = Integer.valueOf(token[1]);
			Integer res = Integer.valueOf(token[2]);

			if (plusSign)
			{
				if (op1.intValue() + op2.intValue() == res.intValue())
				{
					correctNumber++;
				}
			}
			else
			{
				if (op1.intValue() - op2.intValue() == res.intValue())
				{
					correctNumber++;
				}
			}
		}

		System.out.println(correctNumber);
	}
}
