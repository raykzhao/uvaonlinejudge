#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	long x, y;
	long z;

	while (scanf("%ld %ld", &x, &y) == 2)
	{
		z = x;

		while (x >= y)
		{
			z += x / y;
			x = (x / y) + (x % y);
		}

		printf("%ld\n", z);
	}

	return 0;
}
