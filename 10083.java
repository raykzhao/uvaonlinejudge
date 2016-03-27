import java.util.*;
import java.math.*;

class Main
{
	static final String notInteger = "is not an integer with less than 100 digits.";

	public static void main(String args[])
	{
		Scanner console = new Scanner(System.in);

		while (console.hasNext())
		{
			int t = console.nextInt();
			BigInteger tt = BigInteger.valueOf(t);
			int a = console.nextInt();
			int b = console.nextInt();
			
			System.out.print("(" + t + "^" + a + "-1)/(" + t + "^" + b + "-1) ");
			
			if (t == 1)
			{
				System.out.println(notInteger);
				continue;
			}

			if (a == b)
			{
				System.out.println("1");
				continue;
			}

			if ((a - b) * Math.log10(t) > 100.0)
			{
				System.out.println(notInteger);
				continue;
			}

			BigInteger divider = (tt.pow(b)).subtract(BigInteger.valueOf(1));

			BigInteger bigNum = (tt.pow(a)).subtract(BigInteger.valueOf(1));

			BigInteger []divAndRmd = bigNum.divideAndRemainder(divider);

			if (divAndRmd[1].compareTo(BigInteger.valueOf(0)) != 0)
			{
				System.out.println(notInteger);
				continue;
			}

			if ((divAndRmd[0].toString()).length() >= 100)
			{
				System.out.println(notInteger);
			}
			else
			{
				System.out.println(divAndRmd[0].toString());
			}
		}
	}
}
