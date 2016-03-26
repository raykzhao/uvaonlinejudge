import java.util.*;
import java.math.*;

class Main
{
	public static void main (String args[])
	{
		Scanner console = new Scanner(System.in);

		int numCase = console.nextInt();

		for (int i = 0; i < numCase; i++)
		{
			BigInteger n = console.nextBigInteger();

			BigInteger l = BigInteger.valueOf(1);
			BigInteger r = n;
			BigInteger mid;

			while (true)
			{
				mid = r.add(l);
				mid = mid.divide(BigInteger.valueOf(2));

				if ((mid.equals(l)) || (mid.equals(r)))
				{
					break;
				}

				if (n.compareTo(mid.multiply(mid)) == -1)
				{
					r = mid;
				}
				else
				{
					l = mid;
				}
			}

			System.out.println(mid.toString());

			if (i < numCase - 1)
			{
				System.out.println();
			}
		}
	}
}
