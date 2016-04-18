#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str1[1010], str2[1010];
int dp[1010][1010];

int max_value(int a, int b)
{
	return (a > b) ? a : b;
}

void do_dp()
{
	int i, j;
	memset(dp, 0, sizeof(dp));

	for (i = 0; i < strlen(str1); i++)
	{
		for (j = 0; j < strlen(str2); j++)
		{
			if (str1[i] == str2[j])
			{
				dp[i + 1][j + 1] = dp[i][j] + 1;
			}
			else
			{
				dp[i + 1][j + 1] = max_value(dp[i][j + 1], dp[i + 1][j]);
			}
		}
	}
}

int main(int argc, char **argv)
{
	while (gets(str1))
	{
		gets(str2);

		do_dp();
		printf("%d\n", dp[strlen(str1)][strlen(str2)]);
	}

	return 0;
}
