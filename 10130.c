#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long dp[1010][40];
int goods[1010][2];
int weight[110];

long max_value(long a, long b)
{
	return (a > b) ? a : b;
}

int main(int argc, char **argv)
{
	int num_case, cas;
	int n;
	int i, j;
	int m;
	int w;
	int max_weight;
	long sum;

	scanf("%d", &num_case);

	for (cas = 0; cas < num_case; cas++)
	{
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			scanf("%d %d", &(goods[i][0]), &(goods[i][1]));
		}

		scanf("%d", &m);
		max_weight = 0;
		for (i = 0; i < m; i++)
		{
			scanf("%d", weight + i);
			if (weight[i] > max_weight)
			{
				max_weight = weight[i];
			}
		}

		memset(dp, 0, sizeof(dp));

		for (i = 1; i <= n; i++)
		{
			for (j = 0; j <= max_weight; j++)
			{
				if (goods[i - 1][1] > j)
				{
					dp[i][j] = dp[i - 1][j];
				}
				else
				{
					dp[i][j] = max_value(dp[i - 1][j], dp[i - 1][j - goods[i - 1][1]] + ((long)(goods[i - 1][0])));
				}
			}
		}

		sum = 0;
		for (i = 0; i < m; i++)
		{
			sum += dp[n][weight[i]];
		}

		printf("%ld\n", sum);
	}
	return 0;
}
