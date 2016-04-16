#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>

using namespace std;

long graph[300][300];
long residual[300][300];
queue <int> q;
int pred[300];
long cap[300];

int n;

void maxflow()
{
	long totFlow = 0;
	memset(residual, 0, sizeof(residual));

	while (1)
	{
		for (int i = 1; i <= 2 * n + 1; i++)
		{
			pred[i] = -1;
		}

		memset(cap, 0, sizeof(cap));
		cap[0] = 2000000000;

		q = queue <int> ();
		q.push(0);

		while (!q.empty())
		{
			int cur = q.front();
			q.pop();

			int flag = 0;
			for (int x = 1; x <= 2 * n + 1; x++)
			{
				if ((graph[cur][x] - residual[cur][x] > 0) && (pred[x] == -1))
				{
					pred[x] = cur;
					cap[x] = (cap[cur] < graph[cur][x] - residual[cur][x]) ? cap[cur] : (graph[cur][x] - residual[cur][x]);

					if (x != 2 * n + 1)
					{
						q.push(x);
					}
					else
					{
						flag = 1;
						break;
					}
				}
			}

			if (flag)
			{
				break;
			}
		}
		
		long flow = cap[2 * n + 1];
		if (!flow)
		{
			break;
		}

		totFlow += flow;

		for (int cur = 2 * n + 1; cur; cur = pred[cur])
		{
			residual[pred[cur]][cur] += flow;
			residual[cur][pred[cur]] -= flow;
		}
	}

	printf("%ld\n", totFlow);
}

int main(int argc, char **argv)
{
	while (scanf("%d", &n) == 1)
	{
		memset(graph, 0, sizeof(graph));

		for (int i = 1; i <= n; i++)
		{
			long x;
			scanf("%ld", &x);

			graph[2 * i - 1][2 * i] = x;
		}

		int m;
		scanf("%d", &m);
		for (int i = 0; i < m; i++)
		{
			int x, y;
			long c;
			scanf("%d %d %ld", &x, &y, &c);

			graph[2 * x][2 * y - 1] = c;
		}

		int st, ed;
		scanf("%d %d", &st, &ed);
		for (int i = 0; i < st; i++)
		{
			int x;
			scanf("%d", &x);

			graph[0][2 * x - 1] = 2000000000;
		}
		for (int i = 0; i < ed; i++)
		{
			int x;
			scanf("%d", &x);

			graph[2 * x][2 * n + 1] = 2000000000;
		}

		maxflow();
	}

	return 0;
}
