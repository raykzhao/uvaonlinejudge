#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int num_case;

int graph[55][55];
int degree[55];
int output[1100];
int c;

void do_dfs(int x)
{
	int i;

	for (i = 1; i <= 50; i++)
	{
		if (graph[x][i])
		{
			(graph[x][i])--;
			(graph[i][x])--;

			(degree[x])--;
			(degree[i])--;

			do_dfs(i);
		}
	}

	output[c++] = x;
}

int main(int argc, char **argv)
{
	int cas;
	int n;
	int i, x, y;
	int flag;

	scanf("%d", &num_case);
	
	for (cas = 1; cas <= num_case; cas++)
	{
		scanf("%d", &n);

		memset(graph, 0, sizeof(graph));
		memset(degree, 0 ,sizeof(degree));

		for (i = 0; i < n; i++)
		{
			scanf("%d %d", &x, &y);

			(degree[x])++;
			(degree[y])++;

			(graph[x][y])++;
			(graph[y][x])++;
		}

		flag = 0;

		for (i = 1; i <= 50; i++)
		{
			if (degree[i] % 2)
			{
				flag = 1;
				break;
			}
		}

		printf("Case #%d\n", cas);

		if (flag)
		{
			printf("some beads may be lost\n");
		}
		else
		{
			c = 0;
			do_dfs(1);

			flag = 0;
			for (i = 1; i <= 50; i++)
			{
				if (degree[i])
				{
					flag = 1;
					break;
				}
			}

			if (flag)
			{
				printf("some beads may be lost\n");
			}
			else
			{
				for (i = 0; i < c - 1; i++)
				{
					printf("%d %d\n", output[i], output[i + 1]);
				}
			}
		}

		if (cas < num_case)
		{
			printf("\n");
		}
	}
	
	return 0;
}
