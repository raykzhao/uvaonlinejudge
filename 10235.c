#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int prime[10000010];
char str[10];
char str2[10];

void sieve()
{
	long i, j;

	prime[0] = 1;
	prime[1] = 1;
	for (i = 4; i <= 10000000; i += 2)
	{
		prime[i] = 1;
	}

	for (i = 3; i <= ((long)sqrt(10000000)); i += 2)
	{
		if (!prime[i])
		{
			for (j = i * i; j <= 10000000; j += 2 * i)
			{
				prime[j] = 1;
			}
		}
	}
}

int main(int argc, char **argv)
{
	long x;
	int i;
	long x2;

	sieve();

	while (scanf("%ld", &x) == 1)
	{
		if (prime[x])
		{
			printf("%ld is not prime.\n", x);
		}
		else
		{
			sprintf(str, "%ld", x);
			for (i = 0; i < strlen(str); i++)
			{
				str2[strlen(str) - i - 1] = str[i];
			}
			str2[strlen(str)] = 0;

			x2 = atol(str2);

			if ((!prime[x2]) && (x != x2))
			{
				printf("%ld is emirp.\n", x);
			}
			else
			{
				printf("%ld is prime.\n", x);
			}
		}
	}

	return 0;
}
