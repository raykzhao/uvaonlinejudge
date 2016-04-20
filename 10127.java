import java.util.*;
import java.math.*;

class Main
{
	public static void main(String args[])
	{
		Scanner console = new Scanner(System.in);

		while (console.hasNext())
		{
			int x = console.nextInt();
			
			BigInteger ones = BigInteger.valueOf(1);

			while ((ones.mod(BigInteger.valueOf(x))).compareTo(BigInteger.valueOf(0)) != 0)
			{
				ones = (ones.multiply(BigInteger.valueOf(10))).add(BigInteger.valueOf(1));
			}

			System.out.println((ones.toString()).length());
		}
	}
}
