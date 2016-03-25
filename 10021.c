#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int dice_up[6] = {2, 1, 3, 4, 0 ,5};
const int dice_down[6] = {4, 1, 0, 2, 3, 5};
const int dice_left[6] = {5, 0 ,2, 1, 4, 3};
const int dice_right[6] = {1, 3, 2, 5, 4, 0};

typedef struct cube
{
	int dist[6];
	int v, h;
} CUBE;

int num_case;

CUBE graph[15][15];

int st_x, st_y, ed_x, ed_y, n, m;

char str[10];

int queue[1000][3];

void do_bfs()
{
	int l = 0, r = 1;

	queue[l][0] = st_x;
	queue[l][1] = st_y;
	queue[l][2] = 0;

	while (l < r)
	{
		if (queue[l][0] > 0)
		{
			if ((!(graph[queue[l][0] - 1][queue[l][1]].h)) &&
				(graph[queue[l][0]][queue[l][1]].dist[queue[l][2]] + 1 <
				 graph[queue[l][0] - 1][queue[l][1]].dist[dice_up[queue[l][2]]]))
			{
				graph[queue[l][0] - 1][queue[l][1]].dist[dice_up[queue[l][2]]] =
					graph[queue[l][0]][queue[l][1]].dist[queue[l][2]] + 1;

				queue[r][0] = queue[l][0] - 1;
				queue[r][1] = queue[l][1];
				queue[r++][2] = dice_up[queue[l][2]];
			}
		}
		
		if (queue[l][0] < n - 1)
		{
			if ((!(graph[queue[l][0]][queue[l][1]].h)) &&
				(graph[queue[l][0]][queue[l][1]].dist[queue[l][2]] + 1 <
				 graph[queue[l][0] + 1][queue[l][1]].dist[dice_down[queue[l][2]]]))
			{
				graph[queue[l][0] + 1][queue[l][1]].dist[dice_down[queue[l][2]]] =
					graph[queue[l][0]][queue[l][1]].dist[queue[l][2]] + 1;

				queue[r][0] = queue[l][0] + 1;
				queue[r][1] = queue[l][1];
				queue[r++][2] = dice_down[queue[l][2]];
			}
		}
		
		if (queue[l][1] > 0)
		{
			if ((!(graph[queue[l][0]][queue[l][1] - 1].v)) &&
				(graph[queue[l][0]][queue[l][1]].dist[queue[l][2]] + 1 <
				 graph[queue[l][0]][queue[l][1] - 1].dist[dice_left[queue[l][2]]]))
			{
				graph[queue[l][0]][queue[l][1] - 1].dist[dice_left[queue[l][2]]] =
					graph[queue[l][0]][queue[l][1]].dist[queue[l][2]] + 1;

				queue[r][0] = queue[l][0];
				queue[r][1] = queue[l][1] - 1;
				queue[r++][2] = dice_left[queue[l][2]];
			}
		}
		
		if (queue[l][1] < m - 1)
		{
			if ((!(graph[queue[l][0]][queue[l][1]].v)) &&
				(graph[queue[l][0]][queue[l][1]].dist[queue[l][2]] + 1 <
				 graph[queue[l][0]][queue[l][1] + 1].dist[dice_right[queue[l][2]]]))
			{
				graph[queue[l][0]][queue[l][1] + 1].dist[dice_right[queue[l][2]]] =
					graph[queue[l][0]][queue[l][1]].dist[queue[l][2]] + 1;

				queue[r][0] = queue[l][0];
				queue[r][1] = queue[l][1] + 1;
				queue[r++][2] = dice_right[queue[l][2]];
			}
		}

		l++;
	}
}

int main(int argc, char **argv)
{
	int cas, mode;
	int x, y, i, j, k;
	char *token;

	scanf("%d", &num_case);
	
	for (cas = 0; cas < num_case; cas++)
	{
		scanf("%d %d", &m, &n);

		scanf("%d %d", &st_y, &st_x);
		st_x--;
		st_y--;
		
		scanf("%d %d", &ed_y, &ed_x);
		ed_x--;
		ed_y--;
		
		getchar();
		
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				for (k = 0; k < 6; k++)
				{
					graph[i][j].dist[k] = 1000;
				}
				graph[i][j].v = 0;
				graph[i][j].h = 0;
			}
		}

		graph[st_x][st_y].dist[0] = 0;

		mode = 0;

		while (gets(str))
		{
			if (!strlen(str))
			{
				break;
			}

			if (str[0] == 'v')
			{
				mode = 1;
				continue;
			}
			else if (str[0] == 'h')
			{
				mode = 2;
				continue;
			}

			token = strtok(str, " ");
			y = atoi(token) - 1;
			token = strtok(NULL, " ");
			x = atoi(token) - 1;

			if (mode == 1)
			{
				graph[x][y].v = 1;
			}
			else if (mode == 2)
			{
				graph[x][y].h = 1;
			}
		}

		do_bfs();
		
		if (graph[ed_x][ed_y].dist[0] != 1000)
		{
			printf("%d\n", graph[ed_x][ed_y].dist[0]);
		}
		else
		{
			printf("No solution\n");
		}

		if (cas < num_case - 1)
		{
			printf("\n");
		}
	}
	
	return 0;
}
