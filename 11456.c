#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dp_i[2010], dp_d[2010];
int weight[2010];

int max_value(int a, int b)
{
	return (a > b) ? a : b;
}

int main(int argc, char **argv)
{
	int num_case, cas;
	int n;
	int i, j;
	int max;

	scanf("%d", &num_case);

	for (cas = 0; cas < num_case; cas++)
	{
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			scanf("%d", weight + i);
		}

		memset(dp_i, 0, sizeof(dp_i));
		memset(dp_d, 0, sizeof(dp_d));

		for (i = n - 1; i >= 0; i--)
		{
			dp_i[i] = 1;
			dp_d[i] = 1;

			for (j = i + 1; j < n; j++)
			{
				if (weight[i] < weight[j])
				{
					dp_i[i] = max_value(dp_i[i], dp_i[j] + 1);
				}

				if (weight[i] > weight[j])
				{
					dp_d[i] = max_value(dp_d[i], dp_d[j] + 1);
				}
			}
		}

		max = 0;
		for (i = 0; i < n; i++)
		{
			max = max_value(max, dp_i[i] + dp_d[i] - 1);
		}

		printf("%d\n", max);
	}

	return 0;
}
