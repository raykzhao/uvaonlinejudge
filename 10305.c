#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int n, m;

int graph[110][110];
int degree[110];

int main(int argc, char **argv)
{
	int i, j, k;
	int x, y;
	int flag;

	while (scanf("%d %d", &n, &m) == 2)
	{
		if ((!n) && (!m))
		{
			break;
		}

		for (i = 1; i <= n; i++)
		{
			graph[i][0] = 0;
			degree[i] = 0;
		}

		for (i = 0; i < m; i++)
		{
			scanf("%d %d", &x, &y);

			flag = 1;

			for (j = 1; j <= graph[x][0]; j++)
			{
				if (graph[x][j] == y)
				{
					flag = 0;
					break;
				}
			}

			if (flag)
			{
				graph[x][++(graph[x][0])] = y;
				degree[y]++;
			}
		}

		for (i = 0; i < n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				if (!(degree[j]))
				{
					for (k = 1; k <= graph[j][0]; k++)
					{
						degree[graph[j][k]]--;
					}

					degree[j] = -1;

					printf("%d", j);
					
					break;
				}
			}

			if (i < n - 1)
			{
				printf(" ");
			}
			else
			{
				printf("\n");
			}
		}
	}

	return 0;
}
