#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int num_case;
int n, p;
int h[110];
int days[3700];

void calc_hartal()
{
	int i;
	int j;
	int count;

	for (i = 1; i <= n; i++)
	{
		days[i] = 0;
	}

	for (i = 0; i < p; i++)
	{
		for (j = 1; h[i] * j <= n; days[h[i] * (j++)] = 1);
	}
	
	count = 0;

	for (i = 1; i <= n; i++)
	{
		if ((i % 7 != 0) && (i % 7 != 6) && (days[i]))
		{
			count++;
		}
	}

	printf("%d\n", count);
}

int main(int argc, char **argv)
{
	int t, i;
	
	scanf("%d", &num_case);

	for (t = 0; t < num_case; t++)
	{
		scanf("%d %d", &n, &p);
		
		for (i = 0; i < p; i++)
		{
			scanf("%d", h + i);
		}

		calc_hartal();
	}

	return 0;
}
