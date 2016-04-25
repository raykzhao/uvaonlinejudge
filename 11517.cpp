#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int dp[30010];
int n;
int coin[110];

void do_dp()
{
	for (int i = 1; i <= 20000; i++)
	{
		dp[i] = 20000;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 20000; j >= 0; j--)
		{
			if (dp[j] + 1 < dp[j + coin[i]])
			{
				dp[j + coin[i]] = dp[j] + 1;
			}
		}
	}
}

int compar(const void *a, const void *b)
{
	int aa = *((int *)a), bb = *((int *)b);
	return (bb - aa);
}

int main(int argc, char **argv)
{
	int numCase;
	scanf("%d", &numCase);

	for (int cas = 0; cas < numCase; cas++)
	{
		int price;
		scanf("%d", &price);
		scanf("%d", &n);

		for (int i = 0; i < n; i++)
		{
			scanf("%d", coin + i);
		}

		do_dp();

		int minPrice;
		int min = 20000;

		for (minPrice = price; minPrice <= 20000; minPrice++)
		{
			if (dp[minPrice] < min)
			{
				min = dp[minPrice];
				break;
			}
		}

		printf("%d %d\n", minPrice, min);
	}

	return 0;
}
