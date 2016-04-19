#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	long x;
	long long frac;
	long i;

	while (scanf("%ld", &x) == 1)
	{
		if (x <= 7 && x >= 0)
		{
			printf("Underflow!\n");
		}
		else if (x > 13)
		{
			printf("Overflow!\n");
		}
		else if (x < 0)
		{
			if (x % 2)
			{
				printf("Overflow!\n");
			}
			else
			{
				printf("Underflow!\n");
			}
		}
		else
		{
			frac = 1;
			for (i = 1; i <= x; i++)
			{
				frac *= i;
			}

			printf("%lld\n", frac);
		}
	}

	return 0;
}
