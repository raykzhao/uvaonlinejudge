#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str1[110], str2[110];

int dp[110][110];

int max(int a, int b)
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
				dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
			}
		}
	}
}

int main(int argc, char **argv)
{
	int cas;
	for (cas = 1; gets(str1); cas++)
	{
		if (!strcmp(str1, "#"))
		{
			break;
		}

		gets(str2);

		do_dp();
		printf("Case #%d: you can visit at most %d cities.\n", cas, dp[strlen(str1)][strlen(str2)]);
	}
	return 0;
}
