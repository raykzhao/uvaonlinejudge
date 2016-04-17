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
			int a = console.nextInt();

			BigInteger sum = BigInteger.valueOf(0);
			BigInteger ai = BigInteger.valueOf(1);

			for (int i = 1; i <= n; i++)
			{
				ai = ai.multiply(BigInteger.valueOf(a));
				sum = sum.add(ai.multiply(BigInteger.valueOf(i)));
			}

			System.out.println(sum);
		}
	}
}
