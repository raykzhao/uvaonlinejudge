import java.util.*;

class Main
{
	public static void main(String args[])
	{
		Scanner console = new Scanner(System.in);

		TreeSet <String> output = new TreeSet <String> ();

		while (console.hasNext())
		{
			String line = console.nextLine().toLowerCase();

			String[] token = line.split("[^a-z]");

			for (int i = 0; i < token.length; i++)
			{
				if (token[i].length() > 0)
				{
					output.add(token[i]);
				}
			}
		}

		Iterator <String> it = output.iterator();

		while (it.hasNext())
		{
			System.out.println(it.next());
		}
	}
}
