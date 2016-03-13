#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	unsigned long int x, y, z;
	while (scanf("%lu %lu", &x, &y) == 2)
	{
		if (y < x)
		{
			z = y; y = x; x = z;
		}
		z = y - x;
		printf("%lu\n", z);
	}
	return 0;
}
