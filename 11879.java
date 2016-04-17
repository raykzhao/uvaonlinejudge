import java.util.*;
import java.math.*;

class Main
{
	public static void main(String args[])
	{
		Scanner console = new Scanner(System.in);

		while (console.hasNext())
		{
			BigInteger x = console.nextBigInteger();

			if (x.compareTo(BigInteger.valueOf(0)) == 0)
			{
				break;
			}

			if ((x.mod(BigInteger.valueOf(17))).compareTo(BigInteger.valueOf(0)) == 0)
			{
				System.out.println("1");
			}
			else
			{
				System.out.println("0");
			}
		}
	}
}
