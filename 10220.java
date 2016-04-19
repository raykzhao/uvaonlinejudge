import java.util.*;
import java.math.*;

class Main
{
	public static void main(String args[])
	{
		Scanner console = new Scanner(System.in);

		while (console.hasNext())
		{
			int n = console.nextInt();

			BigInteger frac = BigInteger.valueOf(1);

			if ((n == 0) || (n == 1))
			{
				System.out.println("1");
			}
			else
			{
				for (int i = 2; i <= n; i++)
				{
					frac = frac.multiply(BigInteger.valueOf(i));
				}
				
				String digits = frac.toString();
				long sum = 0;
				for (int i = 0; i < digits.length(); i++)
				{
					sum += digits.charAt(i) - '0';
				}

				System.out.println(sum);
			}
		}
	}
}
