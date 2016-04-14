#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <utility>

using namespace std;

map < pair <int, int>, long> graph;

int busy[210];
int n;
long dist[210];

void bellman_ford()
{
	for (int i = 0; i < n - 1; i++)
	{
		for (map < pair <int, int>, long>::iterator it = graph.begin(); it != graph.end(); it++)
		{
			pair <int, int> cur = it->first;

			if (dist[cur.first] + it->second < dist[cur.second])
			{
				dist[cur.second] = dist[cur.first] + it->second;
			}
		}
	}

	for (map < pair <int, int>, long>::iterator it = graph.begin(); it != graph.end(); it++)
	{
		pair <int, int> cur = it->first;
		if (dist[cur.first] + it->second < dist[cur.second])
		{
			dist[cur.second] = -2000000000;
		}
	}
}

int main(int argc, char **argv)
{
	int numCase = 0;

	while (scanf("%d", &n) == 1)
	{
		graph.clear();
		for (int i = 1; i <= n; i++)
		{
			dist[i] = 2000000000;
		}
		dist[1] = 0;

		for (int i = 1; i <= n; i++)
		{
			scanf("%d", busy + i);
		}

		long m;
		scanf("%ld", &m);

		for (long i = 0; i < m; i++)
		{
			int x, y;
			scanf("%d %d", &x, &y);

			long d = (long)(busy[y] - busy[x]);
			graph[make_pair(x, y)] = d * d * d;
		}

		bellman_ford();

		scanf("%ld", &m);

		printf("Set #%d\n", ++numCase);
		for (long i = 0; i < m; i++)
		{
			int x;
			scanf("%d", &x);

			if ((dist[x] < 3) || (dist[x] > 1900000000))
			{
				printf("?\n");
			}
			else
			{
				printf("%ld\n", dist[x]);
			}
		}
	}

	return 0;
}
