#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long weight[100010];

int compar(const void *a, const void *b)
{
	long aa = *((long *)a), bb = *((long *)b);

	if (aa < bb)
	{
		return -1;
	}
	else if (aa == bb)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int main(int argc, char **argv)
{
	int num_case;
	int cas;
	long n, m;
	long i;
	long sum;
	long count;

	scanf("%d", &num_case);

	for (cas = 0; cas < num_case; cas++)
	{
		scanf("%ld %ld", &n, &m);

		for (i = 0; i < n; i++)
		{
			scanf("%ld", weight + i);
		}

		qsort(weight, n, sizeof(long), compar);

		sum = 0;
		count = 0;
		for (i = 0; i < n; i++)
		{
			sum += weight[i];

			if (sum <= m)
			{
				count++;
			}
			else
			{
				break;
			}
		}

		printf("%ld\n", count);
	}

	return 0;
}
