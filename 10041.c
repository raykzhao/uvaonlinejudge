#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int num_case;
int pos[510];

int compar(const void *a, const void *b)
{
	return ((*((int *)a)) - (*((int *)b)));
}

int main(int argc, char **argv)
{
	int cas;
	int n;
	int i;
	long sum;

	scanf("%d", &num_case);

	for (cas = 0; cas < num_case; cas++)
	{
		scanf("%d", &n);
		
		for (i = 0; i < n; i++)
		{
			scanf("%d", pos + i);
		}

		qsort(pos, n, sizeof(int), compar);

		sum = 0;
		for (i = 0; i < n; i++)
		{
			sum += (long)(abs(pos[n / 2] - pos[i]));
		}

		printf("%ld\n",sum);
	}

	return 0;
}
