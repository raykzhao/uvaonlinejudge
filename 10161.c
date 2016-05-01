#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char **argv)
{
	long i;
	long n;
	long s_n;
	long dif;

	while (scanf("%ld", &n) == 1)
	{
		if (!n)
		{
			break;
		}

		if (n == 1)
		{
			puts("1 1");
			continue;
		}

		s_n = (long)ceil(sqrt(n));
		dif = n - (s_n - 1) * (s_n - 1);

		if (s_n % 2)
		{
			if (n <= s_n * s_n - s_n + 1)
			{
				printf("%ld %ld\n", s_n, n - (s_n - 1) * (s_n - 1));
			}
			else
			{
				printf("%ld %ld\n", s_n * s_n - n + 1, s_n);
			}
		}
		else
		{
			if (n <= s_n * s_n - s_n + 1)
			{
				printf("%ld %ld\n", n - (s_n - 1) * (s_n - 1), s_n);
			}
			else
			{
				printf("%ld %ld\n", s_n, s_n * s_n - n + 1);
			}
		}
	}

	return 0;
}
