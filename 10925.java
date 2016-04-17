import java.util.*;
import java.math.*;

class Main
{
	public static void main(String args[])
	{
		Scanner console = new Scanner(System.in);

		int numCase = 0;
		while (console.hasNext())
		{
			int n = console.nextInt();
			int numFriend = console.nextInt();

			if ((n == 0) && (numFriend == 0))
			{
				break;
			}

			numCase++;

			BigInteger sum = BigInteger.valueOf(0);
			for (int i = 0; i < n; i++)
			{
				BigInteger bill = console.nextBigInteger();
				sum = sum.add(bill);
			}

			System.out.println("Bill #" + numCase + " costs " + sum + ": each friend should pay " + sum.divide(BigInteger.valueOf(numFriend)));
			System.out.println();
		}
	}
}
