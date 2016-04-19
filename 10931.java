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

			if (x == 0)
			{
				break;
			}

			String bin = Integer.toBinaryString(x);

			int num = 0;
			for (int i = 0; i < bin.length(); i++)
			{
				if (bin.charAt(i) == '1')
				{
					num++;
				}
			}

			System.out.println("The parity of " + bin + " is " + num + " (mod 2).");
		}
	}
}
