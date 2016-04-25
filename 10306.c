#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int m;
int s;

long coin[50][2];
long dp[50][400][400];

long min(long a, long b)
{
	return (a < b) ? a : b;
}

void do_dp()
{
	int v, i, j;

	for (i = 0; i <= s; i++)
	{
		for (j = 0; j <= s; j++)
		{
			dp[0][i][j] = 1000000000;
		}
	}
	dp[0][0][0] = 0;

	for (v = 0; v < m; v++)
	{
		for (i = 0; i <= s; i++)
		{
			for (j = 0; j <= s; j++)
			{
				if ((coin[v][0] > i) || (coin[v][1] > j))
				{
					dp[v + 1][i][j] = dp[v][i][j];
				}
				else if ((coin[v][0] == i) && (coin[v][1] == j))
				{
					dp[v + 1][i][j] = 1;
				}
				else
				{
					dp[v + 1][i][j] = min(dp[v][i][j], dp[v + 1][i - coin[v][0]][j - coin[v][1]] + 1);
				}
			}
		}
	}
}

int main(int argc, char **argv)
{
	int num_case;
	int i;
	int cas;
	long x;
	long xx;
	long min;

	scanf("%d", &num_case);

	for (cas = 0; cas < num_case; cas++)
	{
		scanf("%d %d", &m, &s);

		for (i = 0; i < m; i++)
		{
			scanf("%ld %ld", &(coin[i][0]), &(coin[i][1]));
		}

		do_dp();

		min = 1000000000;
		for (i = 0; i <= s; i++)
		{
			x = ((long)s) * ((long)s) - ((long)i) * ((long)i);
			xx = (long)sqrt(x);
			
			if (xx * xx == x)
			{
				if (dp[m][i][xx] < min)
				{
					min = dp[m][i][xx];
				}
			}
		}

		if (min == 1000000000)
		{
			puts("not possible");
		}
		else
		{
			printf("%ld\n", min);
		}
	}

	return 0;
}
