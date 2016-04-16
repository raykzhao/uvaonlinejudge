#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>

using namespace std;

int n;
long graph[200][200];
queue <int> q;
int pred[200];
long cap[200];
long residual[200][200];

void max_flow()
{
	memset(residual, 0, sizeof(residual));

	long totFlow = 0;
	while (1)
	{
		pred[1] = -2;
		for (int i = 2; i < n + 50; i++)
		{
			pred[i] = -1;
		}
		memset(cap, 0, sizeof(cap));
		cap[1] = 2000000000;
		q = queue <int> ();
		q.push(1);

		int flag = 0;
		while (!q.empty())
		{
			int cur = q.front();
			q.pop();

			for (int i = 2; i < n + 50; i++)
			{
				if ((pred[i] == -1) && (graph[cur][i] > residual[cur][i]))
				{
					pred[i] = cur;
					cap[i] = (cap[cur] < graph[cur][i] - residual[cur][i]) ? (cap[cur]) : (graph[cur][i] - residual[cur][i]);

					if (i != n)
					{
						q.push(i);
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

		if (!cap[n])
		{
			break;
		}

		totFlow += cap[n];

		for (int i = n; i != 1; i = pred[i])
		{
			residual[pred[i]][i] += cap[n];
			residual[i][pred[i]] -= cap[n];
		}
	}

	printf("%ld\n", totFlow);
}

int main(int argc, char **argv)
{
	int m;
	while (scanf("%d %d", &n, &m) == 2)
	{
		if ((!n) && (!m))
		{
			break;
		}

		memset(graph, 0, sizeof(graph));

		for (int i = 0; i < n - 2; i++)
		{
			int x;
			long c;
			scanf("%d %ld", &x, &c);

			graph[x][x + 50] = c;
		}

		for (int i = 0; i < m; i++)
		{
			int x, y;
			long c;
			scanf("%d %d %ld", &x, &y, &c);

			int xx = x, yy = y;
			if ((x != 1) && (x != n))
			{
				xx += 50;
			}
			if ((y != 1) && (y != n))
			{
				yy += 50;
			}

			graph[xx][y] = c;
			graph[yy][x] = c;
		}

		max_flow();
	}

	return 0;
}
