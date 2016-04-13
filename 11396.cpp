#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <utility>

using namespace std;

int graph[310][310];

int v;

int color[310];

queue < pair <int, int> > q;

int do_color()
{
	color[1] = 0;
	for (int i = 2; i <= v; i++)
	{
		color[i] = -1;
	}

	q = queue < pair <int, int> > ();
	q.push(make_pair(1, 0));

	while (!q.empty())
	{
		pair <int, int> cur = q.front();

		q.pop();

		for (int i = 1; i <= graph[cur.first][0]; i++)
		{
			if (color[graph[cur.first][i]] != cur.second)
			{
				if (color[graph[cur.first][i]] == -1)
				{
					color[graph[cur.first][i]] = (cur.second ^ 1);
					q.push(make_pair(graph[cur.first][i], (cur.second ^ 1)));
				}
			}
			else
			{
				return 0;
			}
		}
	}

	return 1;
}

int main(int argc, char **argv)
{
	while (scanf("%d", &v) == 1)
	{
		if (!v)
		{
			break;
		}

		memset(graph, 0, sizeof(graph));

		int x, y;

		while (scanf("%d %d", &x, &y) == 2)
		{
			if ((!x) && (!y))
			{
				break;
			}

			graph[x][++(graph[x][0])] = y;
			graph[y][++(graph[y][0])] = x;
		}

		if (do_color())
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}

	return 0;
}
