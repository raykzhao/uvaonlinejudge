#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

vector <int> graph[110];

int dis1[110], dis2[110];

queue <int> q;

int n;

int bfs(int st, int *dis)
{
	for (int i = 0; i < n; i++)
	{
		dis[i] = 10010;
	}
	dis[st] = 0;
	q.push(st);

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int i = 0; i < graph[cur].size(); i++)
		{
			if (dis[cur] + 1 < dis[graph[cur][i]])
			{
				dis[graph[cur][i]] = dis[cur] + 1;
				q.push(graph[cur][i]);
			}
		}
	}
}

int main(int argc, char **argv)
{
	int numCase;
	scanf("%d", &numCase);

	for (int cas = 1; cas <= numCase; cas++)
	{
		int m;
		scanf("%d %d", &n, &m);

		for (int i = 0; i < n; i++)
		{
			graph[i].clear();
		}

		for (int i = 0; i < m; i++)
		{
			int u, v;
			scanf("%d %d", &u, &v);

			if (u != v)
			{
				graph[u].push_back(v);
				graph[v].push_back(u);
			}
		}

		int s, d;
		scanf("%d %d", &s, &d);

		bfs(s, dis1);
		bfs(d, dis2);

		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			if (dis1[i] + dis2[i] > ans)
			{
				ans = dis1[i] + dis2[i];
			}
		}

		printf("Case %d: %d\n", cas, ans);
	}

	return 0;
}
