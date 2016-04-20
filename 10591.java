import java.util.*;
import java.math.*;

class Main
{
	public static void main(String args[])
	{
		Scanner console = new Scanner(System.in);

		int numCase = console.nextInt();

		for (int cas = 1; cas <= numCase; cas++)
		{
			Integer x = Integer.valueOf(console.nextInt());
			System.out.print("Case #" + cas + ": " + x + " is ");

			Integer xx = x;
			int sum;
			HashSet <Integer> sumSet = new HashSet <Integer> ();
			while (true)
			{
				String digit = xx.toString();

				sum = 0;
				for (int i = 0; i < digit.length(); i++)
				{
					sum += ((int)(digit.charAt(i) - '0')) * ((int)(digit.charAt(i) - '0'));
				}
				
				if (sum == 1)
				{
					System.out.println("a Happy number.");
					break;
				}

				if (sumSet.contains(Integer.valueOf(sum)))
				{
					System.out.println("an Unhappy number.");
					break;
				}
				else
				{
					sumSet.add(Integer.valueOf(sum));
					xx = Integer.valueOf(sum);
				}
			}
		}
	}
}
