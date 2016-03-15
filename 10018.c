#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
unsigned long x;
char str[20];

void do_add()
{
	int i, k;
	int flag;

	char ch;

	unsigned long y;

	for (k = 0; k < 1000; k++)
	{
		sprintf(str, "%lu", x);

		flag = 0;
		for (i = 0; i < (strlen(str) / 2); i++)
		{
			if (str[i] != str[strlen(str) - i - 1])
			{
				flag = 1;
				break;
			}
		}

		if (!flag)
		{
			printf("%d %lu\n", k, x);
			break;
		}

		for (i = 0; i < (strlen(str) / 2); i++)
		{
			ch = str[i]; 
			str[i] = str[strlen(str) - i - 1];
			str[strlen(str) - i - 1] = ch;
		}

		y = atol(str);

		x += y;
	}
}

int main(int argc, char **argv)
{
	int i;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%lu", &x);

		do_add();
	}

	return 0;
}
