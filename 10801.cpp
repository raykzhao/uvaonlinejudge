#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

queue < pair <int, int> > q;

int elevatorTime[10];
char str[1000];
int numElevator;

vector < pair <int, long> > graph[110][10];

long dist[110][10];

void doSPFA()
{
	for (int i = 0; i < numElevator; i++)
	{
		if (graph[0][i].size())
		{
			dist[0][i] = 0;
		}

		for (vector < pair <int, long> >::iterator it = graph[0][i].begin(); it != graph[0][i].end(); it++)
		{
			dist[it->first][i] = it->second;
			q.push(make_pair(it->first, i));
		}
	}

	while (!q.empty())
	{
		pair <int, int> cur = q.front();
		q.pop();

		for (int i = 0; i < numElevator; i++)
		{
			for (vector < pair <int, long> >::iterator it = graph[cur.first][i].begin(); it != graph[cur.first][i].end(); it++)
			{
				long newDist = dist[cur.first][cur.second] + it->second;
				if (cur.second != i)
				{
					newDist += (long)60;
				}

				if (newDist < dist[it->first][i])
				{
					dist[it->first][i] = newDist;
					q.push(make_pair(it->first, i));
				}
			}
		}
	}
}

int main(int argc, char **argv)
{
	int endFloor;

	while (scanf("%d %d", &numElevator, &endFloor) == 2)
	{
		for (int i = 0; i < numElevator; i++)
		{
			scanf("%d", elevatorTime + i);
		}

		getchar();

		for (int i = 0; i <= 99; i++)
		{
			for (int j = 0; j < numElevator; j++)
			{
				graph[i][j].clear();
			}
		}

		for (int i = 0; i < numElevator; i++)
		{
			int x = -1;

			gets(str);

			char *pch = strtok(str, " ");
			while (pch != NULL)
			{
				if (x != -1)
				{
					long y = ((long)(atoi(pch) - x)) * ((long)(elevatorTime[i]));

					graph[x][i].push_back(make_pair(atoi(pch), y));

					graph[atoi(pch)][i].push_back(make_pair(x, y));
				}

				x = atoi(pch);
				pch = strtok(NULL, " ");
			}
		}

		for (int i = 0; i <= 99; i++)
		{
			for (int j = 0; j < numElevator; j++)
			{
				dist[i][j] = 2000000000;
			}
		}

		doSPFA();

		long min = 2000000000;
		for (int i = 0; i < numElevator; i++)
		{
			if (dist[endFloor][i] < min)
			{
				min = dist[endFloor][i];
			}
		}

		if (min == 2000000000)
		{
			printf("IMPOSSIBLE\n");
		}
		else
		{
			printf("%ld\n", min);
		}
	}

	return 0;
}
