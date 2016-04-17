#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int num_case;

int main(int argc, char **argv)
{
	int cas;
	int n;
	int i;
	long x, y, z;
	long long sum;

	scanf("%d", &num_case);

	for (cas = 0; cas < num_case; cas++)
	{
		scanf("%d", &n);

		sum = 0;
		for (i = 0; i < n; i++)
		{
			scanf("%ld %ld %ld", &x, &y, &z);

			sum += ((long long)x) * ((long long)z);
		}

		printf("%lld\n", sum);
	}

	return 0;
}
