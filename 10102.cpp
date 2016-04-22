#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

const int dif[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

int n;
char graph[1000][1000];
long dist[1000][1000];

vector < pair <int, int> > start;

queue < pair <int, int> > q;

long max(long a, long b)
{
	return (a > b) ? a : b;
}

long do_bfs(int st_x, int st_y)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			dist[i][j] = -1;
		}
	}
	dist[st_x][st_y] = 0;

	q = queue < pair <int, int> > ();
	q.push(make_pair(st_x, st_y));

	while (!q.empty())
	{
		int cur_x = (q.front()).first, cur_y = (q.front()).second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int new_x = cur_x + dif[i][0];
			int new_y = cur_y + dif[i][1];

			if ((new_x >= 0 && new_x < n) && (new_y >= 0 && new_y < n))
			{
				if (dist[new_x][new_y] == -1)
				{
					if (graph[new_x][new_y] == '3')
					{
						return (dist[cur_x][cur_y] + 1);
					}
					else
					{
						dist[new_x][new_y] = dist[cur_x][cur_y] + 1;
						q.push(make_pair(new_x, new_y));
					}
				}
			}
		}
	}
}

int main(int argc, char **argv)
{
	while (scanf("%d", &n) == 1)
	{
		getchar();

		start.clear();

		for (int i = 0; i < n; i++)
		{
			gets(graph[i]);
			
			for (int j = 0; j < n; j++)
			{
				if (graph[i][j] == '1')
				{
					start.push_back(make_pair(i, j));
				}
			}
		}

		long ans = 0;
		for (int i = 0; i < start.size(); i++)
		{
			ans = max(ans, do_bfs(start[i].first, start[i].second));
		}

		printf("%ld\n", ans);
	}

	return 0;
}
