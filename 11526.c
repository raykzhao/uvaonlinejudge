#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int num_case;

int main(int argc, char **argv)
{
	int cas;
	long n;
	long i;
	long long res;
	long p, q;

	scanf("%d", &num_case);
	
	for (cas = 0; cas < num_case; cas++)
	{
		scanf("%ld", &n);

		res = (long long)n;

		for (i = 2; i <= n; i++)
		{
			p = n / i;
			q = n / p;
			
			res += ((long long)(q - i + 1)) * ((long long)p);

			i = q;
		}

		if (n < 0)
		{
			printf("0\n");
		}
		else
		{
			printf("%lld\n", res);
		}
	}

	return 0;
}
