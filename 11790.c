#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long height[10000], width[10000];
long dp_i[10000], dp_d[10000];

int main(int argc, char **argv)
{
	int num_case;
	int cas;
	int n;
	int i, j;
	long max_i, max_d;

	scanf("%d", &num_case);

	for (cas = 1; cas <= num_case; cas++)
	{
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			scanf("%ld", height + i);
		}
		for (i = 0; i < n; i++)
		{
			scanf("%ld", width + i);
		}

		memset(dp_i, 0, sizeof(dp_i));
		memset(dp_d, 0, sizeof(dp_d));
		max_i = 0;
		max_d = 0;
		for (i = 0; i < n; i++)
		{
			dp_i[i] = width[i];
			dp_d[i] = width[i];

			for (j = 0; j < i; j++)
			{
				if (height[i] > height[j])
				{
					if (dp_i[j] + width[i] > dp_i[i])
					{
						dp_i[i] = dp_i[j] + width[i];
					}
				}

				if (height[i] < height[j])
				{
					if (dp_d[j] + width[i] > dp_d[i])
					{
						dp_d[i] = dp_d[j] + width[i];
					}
				}
			}

			if (dp_i[i] > max_i)
			{
				max_i = dp_i[i];
			}

			if (dp_d[i] > max_d)
			{
				max_d = dp_d[i];
			}
		}

		printf("Case %d. ", cas);
		if (max_i >= max_d)
		{
			printf("Increasing (%ld). Decreasing (%ld).\n", max_i, max_d);
		}
		else
		{
			printf("Decreasing (%ld). Increasing (%ld).\n", max_d, max_i);
		}
	}

	return 0;
}
