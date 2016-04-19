#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long dp[50];

void do_dp()
{
	int i;
	dp[0] = (long)0;
	dp[1] = (long)1;
	for (i = 2; i <= 44; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2] + ((long)1);
	}
}
int main(int argc, char **argv)
{
	int n;

	do_dp();

	while (scanf("%d", &n) == 1)
	{
		if (n < 0)
		{
			break;
		}

		printf("%ld %ld\n", dp[n], dp[n] + dp[n - 1] + ((long)1));
	}

	return 0;
}
