#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[100];

int main(int argc, char **argv)
{
	int i;
	int two;
	char ans;

	gets(str);
	while (gets(str))
	{
		if (str[0] == '_')
		{
			break;
		}
		if (str[0] == '|')
		{
			two = 1;
			ans = 0;
			for (i = strlen(str) - 2; i >= 1; i--)
			{
				if (str[i] == 'o')
				{
					ans += two;
				}
				if (str[i] != '.')
				{
					two *= 2;
				}
			}
		}
		putchar(ans);
	}

	return 0;
}
