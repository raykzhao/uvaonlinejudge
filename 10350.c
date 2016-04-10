#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[20];
long dist[130][20];

int main(int argc, char **argv)
{
	int n, m;
	int i, j, k;
	long x;
	long min;

	while (gets(str))
	{
		scanf("%d %d ", &n, &m);

		for (i = 1; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				dist[i][j] = 2000000000;
			}
		}

		for (i = 0; i < n - 1; i++)
		{
			for (j = 0; j < m; j++)
			{
				for (k = 0; k < m; k++)
				{
					scanf("%ld ", &x);

					if (dist[i][j] + x + ((long)2) < dist[i + 1][k])
					{
						dist[i + 1][k] = dist[i][j] + x + ((long)2);
					}
				}
			}
		}

		puts(str);
		
		min = 2000000000;
		for (i = 0; i < m; i++)
		{
			if (dist[n - 1][i] < min)
			{
				min = dist[n - 1][i];
			}
		}
		printf("%ld\n", min);
	}

	return 0;
}
