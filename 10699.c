#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int prime[1000000];
long num_prime[100000];
long count;

void sieve()
{
	long i;
	long j;

	prime[0] = 1;
	prime[1] = 1;

	for (i = 4; i <= 1000000; i += ((long)2))
	{
		prime[i] = 1;
	}

	for (i = 3; i <= 1000; i += 2)
	{
		if (!prime[i])
		{
			for (j = i * i; j <= 1000000; j += ((long)2) * i)
			{
				prime[j] = 1;
			}
		}
	}

	count = 0;
	for (i = 0; i <= 1000000; i++)
	{
		if (!prime[i])
		{
			num_prime[count++] = i;
		}
	}
}

int main(int argc, char **argv)
{
	long x;
	int sum;
	long i;

	sieve();
	
	while (scanf("%ld", &x) == 1)
	{
		if (!x)
		{
			break;
		}

		sum = 0;
		for (i = 0; i < count && num_prime[i] <= x; i++)
		{
			if (!(x % num_prime[i]))
			{
				sum++;
			}
		}

		printf("%ld : %d\n", x, sum);
	}
	
	return 0;
}
