#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <utility>

using namespace std;

typedef struct chara
{
	char ch;
	long num;
} CHARA;

const int dif[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

char graph[1000][1000];
char flag[1000][1000];

CHARA num[30];
int n, m;

queue < pair <int, int> > q;

void do_bfs(int st_x, int st_y)
{
	char ch = graph[st_x][st_y];

	q.push(make_pair(st_x, st_y));
	flag[st_x][st_y] = 1;

	while (!q.empty())
	{
		int cur_x = (q.front()).first;
		int cur_y = (q.front()).second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int new_x = cur_x + dif[i][0];
			int new_y = cur_y + dif[i][1];

			if ((new_x >= 0 && new_x < n) && (new_y >= 0 && new_y < m))
			{
				if ((!flag[new_x][new_y]) && (graph[new_x][new_y] == ch))
				{
					flag[new_x][new_y] = 1;
					q.push(make_pair(new_x, new_y));
				}
			}
		}
	}
}

void do_floodfill()
{
	memset(flag, 0, sizeof(flag));

	for (char i = 'a'; i <= 'z'; i++)
	{
		num[i - 'a'].ch = i;
		num[i - 'a'].num = 0;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!flag[i][j])
			{
				do_bfs(i, j);
				(num[graph[i][j] - 'a'].num)++;
			}
		}
	}
}

int compar(const void *a, const void *b)
{
	CHARA aa = *((CHARA *)a), bb = *((CHARA *)b);

	if (aa.num > bb.num)
	{
		return -1;
	}
	else if (aa.num == bb.num)
	{
		if (aa.ch < bb.ch)
		{
			return -1;
		}
		else if (aa.ch == bb.ch)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	else
	{
		return 1;
	}
}

int main(int argc, char **argv)
{
	int numCase;
	scanf("%d", &numCase);
	getchar();

	for (int cas = 1; cas <= numCase; cas++)
	{
		scanf("%d %d", &n, &m);
		getchar();
		
		for (int i = 0; i < n; i++)
		{
			gets(graph[i]);
		}

		do_floodfill();

		qsort(num, 26, sizeof(CHARA), compar);

		printf("World #%d\n", cas);

		for (char i = 'a'; i <= 'z'; i++)
		{
			if (num[i - 'a'].num)
			{
				printf("%c: %ld\n", num[i - 'a'].ch, num[i - 'a'].num);
			}
		}
	}

	return 0;
}
