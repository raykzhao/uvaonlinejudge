#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <map>

using namespace std;

map <int, int> graph[20010];

queue <int> q;

long dist[20010];

int numCase;
int n, st, ed;

void do_SPFA()
{
	dist[st] = 0;
	q.push(st);

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (map <int, int>::iterator it = graph[cur].begin(); it != graph[cur].end(); it++)
		{
			if (dist[cur] + ((long)it->second) < dist[it->first])
			{
				dist[it->first] = dist[cur] + ((long)it->second);
				q.push(it->first);
			}
		}
	}
}

int main(int argc, char **argv)
{
	scanf("%d", &numCase);

	for (int cas = 1; cas <= numCase; cas++)
	{
		int m;
		scanf("%d %d %d %d", &n, &m, &st, &ed);

		for (int i = 0; i <= n; i++)
		{
			graph[i].clear();
			dist[i] = 2000000000;
		}

		for (int i = 0; i < m; i++)
		{
			int x, y, w;
			scanf("%d %d %d", &x, &y, &w);

			if (graph[x].find(y) == graph[x].end())
			{
				graph[x][y] = w;
			}
			else if (w < graph[x][y])
			{
				graph[x][y] = w;
			}

			if (graph[y].find(x) == graph[y].end())
			{
				graph[y][x] = w;
			}
			else if (w < graph[y][x])
			{
				graph[y][x] = w;
			}
		}

		do_SPFA();

		printf("Case #%d: ", cas);
		if (dist[ed] == 2000000000)
		{
			printf("unreachable\n");
		}
		else
		{
			printf("%ld\n", dist[ed]);
		}
	}

	return 0;
}
