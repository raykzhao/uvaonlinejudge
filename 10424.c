#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str1[30], str2[30];

int calc(char *str)
{
	int i;
	int x;
	int sum = 0;
	char conv[10];
	int sum1;

	for (i = 0; i < strlen(str); i++)
	{
		x = 0;
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			x = str[i] - 'A' + 1;
		}
		else if (str[i] >= 'a' && str[i] <= 'z')
		{
			x = str[i] - 'a' + 1;
		}

		sum += x;
	}

	while (sum >= 10)
	{
		sprintf(conv, "%d", sum);

		sum1 = 0;
		for (i = 0; i < strlen(conv); i++)
		{
			sum1 += conv[i] - '0';
		}

		sum = sum1;
	}

	return sum;
}

int main(int argc, char **argv)
{
	int x, y, t;

	while (gets(str1))
	{
		gets(str2);

		x = calc(str1);
		y = calc(str2);

		if (x > y)
		{
			t = x; x = y; y = t;
		}

		if ((!x) && (!y))
		{
			printf("\n");
		}
		else
		{
			printf("%.2f %%\n", ((double)x) / ((double)y) * ((double)100));
		}
	}

	return 0;
}
