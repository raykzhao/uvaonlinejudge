#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
int num[10010];
long sum[10010];
long dp[10010];

long max(long a, long b)
{
	return (a > b) ? a : b;
}

void do_dp()
{
	int i;
	int j;

	sum[0] = num[0];
	for (i = 1; i < n; i++)
	{
		sum[i] = sum[i - 1] + ((long)num[i]);
	}

	dp[0] = sum[0];
	for (i = 1; i < n; i++)
	{
		dp[i] = max(dp[i - 1], sum[i]);

		for (j = 0; j < i; j++)
		{
			if (sum[i] - sum[j] > dp[i])
			{
				dp[i] = sum[i] - sum[j];
			}
		}
	}
}

int main(int argc, char **argv)
{
	int i;

	while (scanf("%d", &n) == 1)
	{
		if (!n)
		{
			break;
		}

		for (i = 0; i < n; i++)
		{
			scanf("%d", num + i);
		}

		do_dp();
		if (dp[n - 1] > 0)
		{
			printf("The maximum winning streak is %ld.\n", dp[n - 1]);
		}
		else
		{
			printf("Losing streak.\n");
		}
	}

	return 0;
}
