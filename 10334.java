import java.util.*;
import java.math.*;

class Main
{
	public static void main(String args[])
	{
		BigInteger[] fib = new BigInteger[1010];
		fib[0] = BigInteger.valueOf(1);
		fib[1] = BigInteger.valueOf(2);

		for (int i = 2; i <= 1000; i++)
		{
			fib[i] = fib[i - 1].add(fib[i - 2]);
		}

		Scanner console = new Scanner(System.in);

		while (console.hasNext())
		{
			System.out.println(fib[console.nextInt()]);
		}
	}
}
