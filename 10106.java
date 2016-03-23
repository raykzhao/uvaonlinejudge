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
			BigInteger y = console.nextBigInteger();

			x = x.multiply(y);

			System.out.println(x.toString());
		}
	}
}
