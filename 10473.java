import java.util.*;
import java.math.*;

class Main
{
	public static void main(String args[])
	{
		Scanner console = new Scanner(System.in);

		while (console.hasNext())
		{
			String num = ((console.nextLine()).trim()).toUpperCase();

			if (num.charAt(0) == '-')
			{
				break;
			}

			if (num.charAt(0) == '0' && num.charAt(1) == 'X')
			{
				Integer num1 = Integer.valueOf(num.substring(2), 16);
				System.out.println(num1);
			}
			else
			{
				Integer num1 = Integer.valueOf(num, 10);
				System.out.println("0x" + ((Integer.toHexString(num1.intValue())).toUpperCase()));
			}
		}
	}
}
