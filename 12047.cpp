#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <map>

using namespace std;

long dis1[10010], dis2[10010];

queue <long> q;

long n;

map <long, map <long, long> > graph1;
map <long, map <long, long> > graph2;

void addedge(long u, long v, long d, map <long, map <long, long> > &graph)
{
	if (graph[u].find(v) == graph[u].end())
	{
		graph[u][v] = d;
	}
	else
	{
		if (d > graph[u][v])
		{
			graph[u][v] = d;
		}
	}
}

void bfs(long st, long *dis, map <long, map <long, long> > graph)
{
	for (long i = 1; i <= n; i++)
	{
		dis[i] = 1000000000;
	}
	dis[st] = 0;

	q.push(st);

	while (!q.empty())
	{
		long cur = q.front();
		q.pop();

		for (map <long, long>::iterator it = graph[cur].begin(); it != graph[cur].end(); it++)
		{
			long v = it->first;
			long d = it->second;
			if (dis[cur] + d < dis[v])
			{
				dis[v] = dis[cur] + d;
				q.push(v);
			}
		}
	}
}

int main(int argc, char **argv)
{
	int numCase;
	scanf("%d", &numCase);

	for (int cas = 0; cas < numCase; cas++)
	{
		long m, st, ed, p;

		scanf("%ld %ld %ld %ld %ld", &n, &m, &st, &ed, &p);

		graph1.clear();
		graph2.clear();
		for (long i = 1; i <= n; i++)
		{
			graph1[i] = map <long, long> ();
			graph2[i] = map <long, long> ();
		}

		for (long i = 0; i < m; i++)
		{
			long u, v, d;
			scanf("%ld %ld %ld", &u, &v, &d);
			addedge(u, v, d, graph1);
			addedge(v, u, d, graph2);
		}

		bfs(st, dis1, graph1);
		bfs(ed, dis2, graph2);

		long ans = -1;

		for (map <long, map <long, long> >::iterator it1 = graph1.begin(); it1 != graph1.end(); it1++)
		{
			long u = it1->first;
			for (map <long, long>::iterator it2 = graph1[u].begin(); it2 != graph1[u].end(); it2++)
			{
				long v = it2->first;
				
				if (dis1[u] + it2->second + dis2[v] <= p)
				{
					if (it2->second > ans)
					{
						ans = it2->second;
					}
				}
			}
		}

		printf("%ld\n", ans);
	}
	return 0;
}
