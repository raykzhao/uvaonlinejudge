#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int num_case;

int main(int argc, char **argv)
{
	int cas;
	int n;
	int i;
	int min, max;
	int x;

	scanf("%d", &num_case);

	for (cas = 0; cas < num_case; cas++)
	{
		scanf("%d", &n);

		min = 100; max = -1;
		for (i = 0; i < n; i++)
		{
			scanf("%d", &x);
			if (x < min)
			{
				min = x;
			}
			if (x > max)
			{
				max = x;
			}
		}

		printf("%d\n", 2 * (max - min));
	}

	return 0;
}
