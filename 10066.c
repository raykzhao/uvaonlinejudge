#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n1, n2;
int num1[110], num2[110];
int dp[110][110];

int max(int a, int b)
{
	return (a > b) ? a : b;
}

void do_dp()
{
	int i, j;

	memset(dp, 0, sizeof(dp));

	for (i = 0; i < n1; i++)
	{
		for (j = 0; j < n2; j++)
		{
			if (num1[i] == num2[j])
			{
				dp[i + 1][j + 1] = dp[i][j] + 1;
			}
			else
			{
				dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
			}
		}
	}
}

int main(int argc, char **argv)
{
	int i;
	int cas;

	for (cas = 1; scanf("%d %d", &n1, &n2) == 2; cas++)
	{
		if ((!n1) && (!n2))
		{
			break;
		}

		for (i = 0; i < n1; i++)
		{
			scanf("%d", num1 + i);
		}
		for (i = 0; i < n2; i++)
		{
			scanf("%d", num2 + i);
		}

		do_dp();
		printf("Twin Towers #%d\nNumber of Tiles : %d\n\n", cas, dp[n1][n2]);
	}

	return 0;
}
