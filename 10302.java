import java.util.*;
import java.math.*;

class Main
{
	public static void main(String args[])
	{
		Scanner console = new Scanner(System.in);

		BigInteger[] dp = new BigInteger[50010];

		dp[0] = BigInteger.valueOf(0);
		for (int i = 1; i <= 50000; i++)
		{
			BigInteger x = BigInteger.valueOf(i);
			x = x.pow(3);
			dp[i] = dp[i - 1].add(x);
		}

		while (console.hasNext())
		{
			System.out.println(dp[console.nextInt()]);
		}
	}
}
