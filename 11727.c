#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int num_case;

int salary[5];

int compar(const void *a, const void *b)
{
	return (*((int *)a) - *((int *)b));
}

int main(int argc, char **argv)
{
	int cas;
	int i;

	scanf("%d", &num_case);

	for (cas = 1; cas <= num_case; cas++)
	{
		for (i = 0; i < 3; i++)
		{
			scanf("%d", salary + i);
		}

		qsort(salary, 3, sizeof(int), compar);
		printf("Case %d: %d\n", cas, salary[1]);
	}

	return 0;
}
