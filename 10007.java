import java.util.*;
import java.math.*;

class Main
{
	public static void main(String args[])
	{
		Scanner console = new Scanner(System.in);

		int n;
		int i;
		BigInteger sum;

		while (true)
		{
			n = console.nextInt();

			if (n == 0)
			{
				break;
			}

			sum = new BigInteger("1");
			for (i = n + 2; i <= 2 * n; i++)
			{
				sum = sum.multiply(BigInteger.valueOf(i));
			}

			System.out.println(sum.toString());
		}
	}
}
