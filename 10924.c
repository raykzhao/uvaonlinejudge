#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int prime[2040];
char str[40];

void sieve()
{
	int i, j;
	prime[0] = 1;
	
	for (i = 4; i <= 2000; i += 2)
	{
		prime[i] = 1;
	}

	for (i = 3; i <= (int)(sqrt(2000)); i += 2)
	{
		if (!prime[i])
		{
			for (j = i * i; j <= 2000; j += 2 * i)
			{
				prime[j] = 1;
			}
		}
	}
}

int main(int argc, char **argv)
{
	int i;
	int sum;

	sieve();

	while (gets(str))
	{
		sum = 0;
		for (i = 0; i < strlen(str); i++)
		{
			if (str[i] >= 'a' && str[i] <= 'z')
			{
				sum += str[i] - 'a' + 1;
			}
			else if (str[i] >= 'A' && str[i] <= 'Z')
			{
				sum += str[i] - 'A' + 27;
			}
		}

		if (prime[sum])
		{
			printf("It is not a prime word.\n");
		}
		else
		{
			printf("It is a prime word.\n");
		}
	}
	return 0;
}
