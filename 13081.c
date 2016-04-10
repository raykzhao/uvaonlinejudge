#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long num_case;
long long l, r;

long long get_xor(long long x)
{
	switch (x % ((long long)4))
	{
		case 0:
			return x + 1;
		case 1:
			return 0;
		case 2:
			return x;
		case 3:
			return 1;
	}
}

int main(int argc, char **argv)
{
	long i;
	long long x;
	long long sum;

	scanf("%ld", &num_case);

	for (i = 0; i < num_case; i++)
	{
		scanf("%lld %lld", &l, &r);

		if (r - l >= 3)
		{
			printf("0\n");
		}
		else
		{
			sum = get_xor(l);

			for (x = l + 1; x <= r; x++)
			{
				sum &= get_xor(x);
			}

			printf("%lld\n", sum);
		}
	}

	return 0;
}
