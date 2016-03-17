import java.util.*;
import java.math.*;

class Main 
{
	public static void main(String args[])
	{
		Scanner console = new Scanner(System.in);

		BigInteger one = new BigInteger("1");
		BigInteger two = new BigInteger("2");
		BigInteger zero = new BigInteger("0");

		while (console.hasNext())
		{
			BigInteger n = console.nextBigInteger();

			if (n.compareTo(zero) < 0)
			{
				break;
			}

			BigInteger n1 = n.add(one);

			n = n.multiply(n1);
			n = n.divide(two);
			n = n.add(one);

			System.out.println(n.toString());
		}
	}
}
