import java.util.*;
import java.math.*;

class Main
{
	public static void main(String args[])
	{
		Scanner console = new Scanner(System.in);

		while (console.hasNext())
		{
			String str = (console.nextLine()).trim();
			BigInteger x = new BigInteger(str);

			if (x.compareTo(BigInteger.valueOf(0)) == 0)
			{
				break;
			}

			System.out.print(str);

			if ((x.mod(BigInteger.valueOf(11))).compareTo(BigInteger.valueOf(0)) == 0)
			{
				System.out.println(" is a multiple of 11.");
			}
			else
			{
				System.out.println(" is not a multiple of 11.");
			}
		}
	}
}
