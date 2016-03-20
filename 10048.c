#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int v;
int dist[110][110];

int max(int x, int y)
{
	return ((x > y) ? x : y);
}

void floyd()
{
	int i, j, k;
	
	for (k = 1; k <= v; k++)
	{
		for (i = 1; i <= v; i++)
		{
			for (j = 1; j <= v; j++)
			{
				if (dist[i][j] > max(dist[i][k], dist[k][j]))
				{
					dist[i][j] = max(dist[i][k], dist[k][j]);
				}
			}
		}
	}
}

int main(int argc, char **argv)
{
	int cas = 1;
	int e, q;
	int i, j;
	int x, y, w;
	int flag = 0;

	while (1)
	{
		scanf("%d %d %d", &v, &e, &q);

		if ((!v) && (!e) && (!q))
		{
			break;
		}

		if (flag)
		{
			printf("\n");
		}

		for (i = 1; i <= v; i++)
		{
			for (j = 1; j <= v; j++)
			{
				if (i == j)
				{
					dist[i][j] = 0;
				}
				else
				{
					dist[i][j] = 10000;
				}
			}
		}

		for (i = 0; i < e; i++)
		{
			scanf("%d %d %d", &x, &y, &w);

			dist[x][y] = w;
			dist[y][x] = w;
		}

		floyd();

		printf("Case #%d\n", cas);

		for (i = 0; i < q; i++)
		{
			scanf("%d %d", &x, &y);

			if (dist[x][y] != 10000)
			{
				printf("%d\n", dist[x][y]);
			}
			else
			{
				printf("no path\n");
			}
		}

		cas++;
		flag = 1;
	}

	return 0;
}
