#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int age[110];

int main(int argc, char **argv)
{
	long n;
	long i;
	int x, j;

	while (1)
	{
		scanf("%ld", &n);

		if (!n)
		{
			break;
		}

		for (i = 1; i < 100; i++)
		{
			age[i] = 0;
		}

		for (i = 0; i < n; i++)
		{
			scanf("%d", &x);
			age[x]++;
		}

		for (x = 1; x < 100; x++)
		{
			if (age[x])
			{
				break;
			}
		}

		printf("%d", x);

		for (j = 1; j < age[x]; j++)
		{
			printf(" %d", x);
		}

		for (i = x + 1; i < 100; i++)
		{
			for (j = 0; j < age[i]; j++)
			{
				printf(" %d", i);
			}
		}

		printf("\n");
	}

	return 0;
}
