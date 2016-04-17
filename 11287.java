import java.util.*;
import java.math.*;

class Main
{
	public static void main(String args[])
	{
		Scanner console = new Scanner(System.in);

		while (console.hasNext())
		{
			BigInteger p = console.nextBigInteger();
			BigInteger a = console.nextBigInteger();

			if ((p.compareTo(BigInteger.valueOf(0)) == 0) && 
				(a.compareTo(BigInteger.valueOf(0)) == 0))
			{
				break;
			}

			if (p.isProbablePrime(100))
			{
				System.out.println("no");
			}
			else
			{
				p = a.modPow(p, p);
				if (p.compareTo(a) == 0)
				{
					System.out.println("yes");
				}
				else
				{
					System.out.println("no");
				}
			}
		}
	}
}
