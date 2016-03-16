import java.util.*;
import java.math.*;

class Main
{
	public static void main(String args[])
	{
		Scanner console = new Scanner(System.in);
		int blank = 0;

		BigInteger zero = new BigInteger("0");
		BigInteger four = new BigInteger("4");
		BigInteger oneHundred = new BigInteger("100");
		BigInteger fourHundred = new BigInteger("400");
		BigInteger fifteen = new BigInteger("15");
		BigInteger fiftyFive = new BigInteger("55");
		
		while (console.hasNext())
		{
			BigInteger year = console.nextBigInteger();

			int leap = 0;
			int flag = 0;

		
			if (blank == 1)
			{
				System.out.println();
			}

			if (((year.mod(fourHundred)).compareTo(zero) == 0) ||
				(((year.mod(four)).compareTo(zero) == 0) &&
				((year.mod(oneHundred)).compareTo(zero) != 0)))
			{
				System.out.println("This is leap year.");
				leap = 1;
				flag = 1;
			}

			if ((year.mod(fifteen)).compareTo(zero) == 0)
			{
				System.out.println("This is huluculu festival year.");
				flag = 1;
			}

			if ((leap == 1) && ((year.mod(fiftyFive)).compareTo(zero) == 0))
			{
				System.out.println("This is bulukulu festival year.");
				flag = 1;
			}

			if (flag == 0)
			{
				System.out.println("This is an ordinary year.");
			}

			blank = 1;
		}
	}
}
