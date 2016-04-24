#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long num[100010][20];

int main(int argc, char **argv)
{
	long n;
	int x;
	long i;
	int j;
	long m;
	long a, b, t;
	int ans;

	while (scanf("%ld", &n) == 1)
	{
		memset(num, 0, sizeof(num));

		for (i = 1; i <= n; i++)
		{
			for (j = 0; j <= 9; j++)
			{
				num[i][j] = num[i - 1][j];
			}

			scanf("%d", &x);
			num[i][x]++;
		}

		scanf("%ld", &m);

		for (i = 0; i < m; i++)
		{
			scanf("%ld %ld", &a, &b);

			if (a > b)
			{
				t = a; a = b; b = t;
			}

			ans = 0;
			for (j = 0; j <= 9; j++)
			{
				if (num[b][j] - num[a - 1][j] > 0)
				{
					ans++;
				}
			}

			printf("%d\n", ans);
		}
	}

	return 0;
}
