#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long sum[510];

long gcd(long a, long b)
{
	long t;
	if (a < b)
	{
		t = a; a = b; b = t;
	}

	while (b)
	{
		t = b;
		b = a % b;
		a = t;
	}

	return a;
}

void gcdsum()
{
	int i, j;
	sum[2] = gcd(1, 2);

	for (i = 3; i <= 500; i++)
	{
		sum[i] = sum[i - 1];
		for (j = 1; j < i; j++)
		{
			sum[i] += gcd(j, i);
		}
	}
}

int main(int argc, char **argv)
{
	int x;
	
	gcdsum();

	while (scanf("%d", &x) == 1)
	{
		if (!x)
		{
			break;
		}

		printf("%ld\n", sum[x]);
	}

	return 0;
}
