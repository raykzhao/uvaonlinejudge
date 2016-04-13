#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char di[4] = {'N', 'L', 'S', 'O'};
const int move[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int n, m;
long s;

char map[110][110];
char inst[50010];

void do_inst()
{
	long i;
	int j, k;
	int cur_x, cur_y, cur_di;
	int new_x, new_y;
	int flag = 0;
	int sum = 0;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			for (k = 0; k < 4; k++)
			{
				if (map[i][j] == di[k])
				{
					cur_x = i;
					cur_y = j;
					cur_di = k;
					flag = 1;
					break;
				}
			}

			if (flag)
			{
				break;
			}
		}

		if (flag)
		{
			break;
		}
	}

	for (i = 0; i < s; i++)
	{
		switch (inst[i])
		{
			case 'D':
				cur_di = (cur_di + 1) % 4;
				break;
			case 'E':
				cur_di--;
				if (cur_di < 0)
				{
					cur_di = 3;
				}
				break;
			case 'F':
				new_x = cur_x + move[cur_di][0];
				new_y = cur_y + move[cur_di][1];

				if ((new_x >= 0) && (new_x < n) && (new_y >= 0) && (new_y < m))
				{
					if (map[new_x][new_y] != '#')
					{
						cur_x = new_x;
						cur_y = new_y;
					}
				}

				break;
		}

		switch (map[cur_x][cur_y])
		{
			case '*':
				sum++;
				map[cur_x][cur_y] = '.';
				break;
			default:
				break;
		}
	}

	printf("%d\n", sum);
}

int main(int argc, char **argv)
{
	int i;

	while (scanf("%d %d %ld", &n, &m, &s) == 3)
	{
		if ((!n) && (!m) && (!s))
		{
			break;
		}

		getchar();
		memset(map, 0, sizeof(map));

		for (i = 0; i < n; i++)
		{
			gets(map[i]);
		}

		gets(inst);

		do_inst();
	}

	return 0;
}
