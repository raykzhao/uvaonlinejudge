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

			if (x < 0)
			{
				break;
			}

			System.out.println(Integer.toString(x, 3));
		}
	}
}
