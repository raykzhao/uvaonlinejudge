import java.util.*;

class Main
{
	public static void main(String args[])
	{
		final String verb = "(hate|love|know|like)s*";
		final String noun = "(tom|jerry|goofy|mickey|jimmy|dog|cat|mouse)";
		final String article = "(a|the)";
		final String actor = "(" + noun + "|" + article + " " + noun + ")";
		final String activeList = actor + "( and " + actor + ")*";
		final String action = activeList + " " + verb + " " + activeList;
		final String statement = action + "( , " + action + ")*";

		Scanner console = new Scanner(System.in);

		while (console.hasNext())
		{
			String str = console.nextLine();

			if (str.matches(statement))
			{
				System.out.println("YES I WILL");
			}
			else
			{
				System.out.println("NO I WON'T");
			}
		}
	}
}
