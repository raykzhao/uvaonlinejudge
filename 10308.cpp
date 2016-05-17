#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>

using namespace std;

map <int, map <int, long> > graph;
char str[100];
long ans;
int visited[10010];

void addedge(int u, int v, long d)
{
	if (u == v)
	{
		return;
	}

	if (graph.find(u) == graph.end())
	{
		graph[u] = map <int, long> ();
	}

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

long dfs(int u)
{
	visited[u] = 1;

	long max = 0;
	for (map <int, long>::iterator it = graph[u].begin(); it != graph[u].end(); it++)
	{
		int v = it->first;
		long d = it->second;

		if (!visited[v])
		{
			long subdist = dfs(v) + d;

			if (max + subdist > ans)
			{
				ans = max + subdist;
			}

			if (subdist > max)
			{
				max = subdist;
			}
		}
	}

	return max;
}

void do_sp()
{
	memset(visited, 0, sizeof(visited));
	ans = 0;
	dfs(1);

	printf("%ld\n", ans);
	graph.clear();
}

int main(int argc, char **argv)
{
	while (gets(str))
	{
		if (strlen(str))
		{
			int u, v;
			long d;
			sscanf(str, "%d %d %ld", &u, &v, &d);

			addedge(u, v, d);
			addedge(v, u, d);
		}
		else
		{
			do_sp();
		}
	}
	do_sp();

	return 0;
}
