#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	long n;
	unsigned long nn;
	int i;
	unsigned long endian;

	while (scanf("%ld", &n) == 1)
	{
		nn = n;

		endian = 0;
		for (i = 0; i < 4; i++)
		{
			endian <<= 8;
			endian += nn & 255;
			nn >>= 8;
		}

		if (endian > 2147483647l)
		{
			endian = 4294967295l - endian + 1;
			printf("%ld converts to -%ld\n", n, endian);
		}
		else
		{
			printf("%ld converts to %ld\n", n, endian);
		}
	}

	return 0;
}
