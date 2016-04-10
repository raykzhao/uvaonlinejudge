#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <utility>

using namespace std;

const int direction[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

int n, m;

long graph[1010][1010];

queue < pair <int, int> > q;

void doBFS(int stX, int stY)
{
	graph[stX][stY] = 0;

	q.push(make_pair(stX, stY));

	while (!q.empty())
	{
		int curX = (q.front()).first, curY = (q.front()).second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int newX = curX + direction[i][0];
			int newY = curY + direction[i][1];

			if ((newX >= 0) && (newX < n) && (newY >= 0) && (newY < m))
			{
				if (graph[newX][newY] != -1)
				{
					if (graph[curX][curY] + 1 < graph[newX][newY])
					{
						graph[newX][newY] = graph[curX][curY] + 1;
						q.push(make_pair(newX, newY));
					}
				}
			}
		}
	}
}

int main(int argc, char **argv)
{
	while (scanf("%d %d", &n, &m) == 2)
	{
		if ((!n) && (!m))
		{
			break;
		}

		int row;
		scanf("%d", &row);

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				graph[i][j] = 1100000;
			}
		}

		for (int i = 0; i < row; i++)
		{
			int rowIndex, count;

			scanf("%d %d", &rowIndex, &count);

			for (int j = 0; j < count; j++)
			{
				int x;
				scanf("%d", &x);
				
				graph[rowIndex][x] = -1;
			}
		}

		int stX, stY, edX, edY;
		scanf("%d %d %d %d", &stX, &stY, &edX, &edY);

		doBFS(stX, stY);

		printf("%d\n", graph[edX][edY]);
	}

	return 0;
}
