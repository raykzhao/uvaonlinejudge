#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	int ch;
	int count = 0;
	
	while ((ch = getchar()) != EOF)
	{
		if (ch == '"')
		{
			if (count % 2)
			{
				putchar('\'');
				putchar('\'');
			}
			else
			{
				putchar('`');
				putchar('`');
			}
			count++;
		}
		else
		{
			putchar(ch);
		}
	}
	return 0;
}
