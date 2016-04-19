#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[100000];
char palindrome[100000];

int main(int argc, char **argv)
{
	long i;
	long c;
	int flag;

	while (gets(str))
	{
		if (!strcmp(str, "DONE"))
		{
			break;
		}

		c = 0;
		for (i = 0; i < strlen(str); i++)
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
			{
				palindrome[c++] = str[i];
			}
			else if (str[i] >= 'a' && str[i] <= 'z')
			{
				palindrome[c++] = str[i] - 'a' + 'A';
			}
		}
		palindrome[c] = 0;

		flag = 1;
		for (i = 0; i < strlen(palindrome) / 2; i++)
		{
			if (palindrome[i] != palindrome[strlen(palindrome) - i - 1])
			{
				flag = 0;
				break;
			}
		}

		if (flag)
		{
			puts("You won't be eaten!");
		}
		else
		{
			puts("Uh oh..");
		}
	}

	return 0;
}
