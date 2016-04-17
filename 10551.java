import java.util.*;
import java.math.*;

class Main
{
	public static void main(String args[])
	{
		Scanner console = new Scanner(System.in);

		while (console.hasNext())
		{
			int base = console.nextInt();

			if (base == 0)
			{
				break;
			}

			String num1 = console.next();
			String num2 = console.next();

			BigInteger bigNum1 = new BigInteger(num1, base);
			BigInteger bigNum2 = new BigInteger(num2, base);

			System.out.println((bigNum1.mod(bigNum2)).toString(base));
		}
	}
}
