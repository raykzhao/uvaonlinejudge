#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long square[100010];

void gen_square()
{
	long i;

	for (i = 1; i <= 100000; i++)
	{
		square[i] = square[i - 1];
		if (sqrt(i) == (double)((int)sqrt(i)))
		{
			square[i]++;
		}
	}
}

int main(int argc, char **argv)
{
	long a, b;
	long x;
	gen_square();

	while (scanf("%ld %ld", &a, &b) == 2)
	{
		if ((!a) && (!b))
		{
			break;
		}

		if (a > b)
		{
			x = a; a = b; b = x;
		}

		x = square[b] - square[a];

		if (sqrt(a) == (double)((int)sqrt(a)))
		{
			x++;
		}

		printf("%ld\n", x);
	}

	return 0;
}
