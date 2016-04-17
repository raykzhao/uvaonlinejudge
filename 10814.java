import java.util.*;
import java.math.*;

class Main
{
	public static void main(String args[])
	{
		Scanner console = new Scanner(System.in);

		int numCase = console.nextInt();
		for (int i = 0; i < numCase; i++)
		{
			BigInteger num1 = console.nextBigInteger();
			console.next();
			BigInteger num2 = console.nextBigInteger();

			BigInteger gcd = num1.gcd(num2);
			
			System.out.println(num1.divide(gcd) + " / " + num2.divide(gcd));
		}
	}
}
