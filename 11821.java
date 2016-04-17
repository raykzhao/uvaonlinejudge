import java.util.*;
import java.math.*;

class Main
{
	public static void main(String args[])
	{
		Scanner console = new Scanner(System.in);

		int numCase = console.nextInt();

		for (int cas = 0; cas < numCase; cas++)
		{
			BigDecimal sum = BigDecimal.valueOf(0);

			while (console.hasNext())
			{
				BigDecimal x = console.nextBigDecimal();

				if (x.compareTo(BigDecimal.valueOf(0)) == 0)
				{
					break;
				}

				sum = sum.add(x);
			}

			sum = sum.stripTrailingZeros();
			System.out.println(sum.toPlainString());
		}
	}
}
