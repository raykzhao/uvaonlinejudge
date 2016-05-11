#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, m;

int cap[100][100];
double cost[100][100];

int prev[100];
double dis[100];
int q[100000];

void do_bfs()
{
	int i;
	int l = 0, r = 1;
	int cur;

	memset(prev, 0, sizeof(prev));
	prev[0] = -1;

	dis[0] = 0;
	for (i = 1; i <= n + m + 1; i++)
	{
		dis[i] = 1000000000;
	}

	q[0] = 0;
	while (l < r)
	{
		cur = q[l++];

		for (i = 1; i <= n + m + 1; i++)
		{
			if (cap[cur][i] > 0 && dis[cur] + cost[cur][i] < dis[i])
			{
				dis[i] = dis[cur] + cost[cur][i];
				prev[i] = cur;

				q[r++] = i;
			}
		}
	}
}

void do_ek()
{
	int v;
	double ans = 0.0;

	while (1)
	{
		do_bfs();

		if (dis[n + m + 1] >= 1000000000)
		{
			break;
		}

		for (v = n + m + 1; v != -1; v = prev[v])
		{
			cap[prev[v]][v]--;
			cap[v][prev[v]]++;
		}

		ans += dis[n + m + 1];
	}

	printf("%.2f\n", ans / ((double)n) + 1e-8);
}

int main(int argc, char **argv)
{
	int i, j;
	double c;

	while (scanf("%d %d", &n, &m) == 2)
	{
		if ((!n) && (!m))
		{
			break;
		}

		memset(cap, 0, sizeof(cap));
		memset(cost, 0, sizeof(cost));

		for (i = 1; i <= n; i++)
		{
			cap[0][i] = 1;

			for (j = 1; j <= m; j++)
			{
				scanf("%lf", &c);

				cap[i][n + j] = 1;

				cost[i][n + j] = c;
				cost[n + j][i] = -c;
			}
		}

		for (j = 1; j <= m; j++)
		{
			cap[n + j][n + m + 1] = 1;
		}

		do_ek();
	}

	return 0;
}
