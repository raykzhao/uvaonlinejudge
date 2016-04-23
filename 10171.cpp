#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

typedef struct node
{
	char age;
	int x, w;
} NODE;

vector <NODE> graph[30];

long dist[2][30];

queue <int> q;

void do_bfs(char st, int ind, char age)
{
	for (int i = 0; i < 26; i++)
	{
		dist[ind][i] = 1000000000;
	}

	dist[ind][st] = 0;
	q.push(st);

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int i = 0; i < graph[cur].size(); i++)
		{
			if (graph[cur][i].age == age)
			{
				if (dist[ind][cur] + graph[cur][i].w < dist[ind][graph[cur][i].x])
				{
					dist[ind][graph[cur][i].x] = dist[ind][cur] + graph[cur][i].w;
					q.push(graph[cur][i].x);
				}
			}
		}
	}
}

int main(int argc, char **argv)
{
	long n;
	while (scanf("%ld", &n) == 1)
	{
		if (!n)
		{
			break;
		}

		getchar();

		for (int i = 0; i < 26; i++)
		{
			graph[i].clear();
		}

		for (int i = 0; i < n; i++)
		{
			char age, di, a, b;
			int w;
			scanf("%c %c %c %c %d", &age, &di, &a, &b, &w);
			getchar();

			NODE newNode;
			newNode.x = b - 'A';
			newNode.age = age;
			newNode.w = w;
			graph[a - 'A'].push_back(newNode);

			if (di == 'B')
			{
				newNode.x = a - 'A';
				graph[b - 'A'].push_back(newNode);
			}
		}

		char st1, st2;
		scanf("%c %c", &st1, &st2);
		getchar();

		do_bfs(st1 - 'A', 0, 'Y');
		do_bfs(st2 - 'A', 1, 'M');

		long min = 1000000000;

		for (int i = 0; i < 26; i++)
		{
			if (dist[0][i] + dist[1][i] < min)
			{
				min = dist[0][i] + dist[1][i];
			}
		}

		if (min < 1000000000)
		{
			printf("%ld", min);

			for (int i = 0; i < 26; i++)
			{
				if (dist[0][i] + dist[1][i] == min)
				{
					printf(" %c", i + 'A');
				}
			}
			printf("\n");
		}
		else
		{
			puts("You will never meet.");
		}
	}

	return 0;
}
