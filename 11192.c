#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[110];

void do_reverse(char *str, int len)
{
	int i;
	char ch;

	for (i = 0; i < len / 2; i++)
	{
		ch = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = ch;
	}
}

int main(int argc, char **argv)
{
	int n;
	int i;

	while (scanf("%d %s", &n, str) == 2)
	{
		if (!n)
		{
			break;
		}

		getchar();
		int l = strlen(str) / n;

		for (i = 0; i < strlen(str); i += l)
		{
			do_reverse(str + i, l);
		}

		puts(str);
	}

	return 0;
}
