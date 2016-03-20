#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <set>

using namespace std;

typedef struct state
{
	char mat[3][3];
	int c, x, y;
	char step[50];
} STATE;

STATE q[362890];
set <unsigned long> existed;
int num_case;
int l, r;

unsigned long calc_key(char mat[3][3])
{
	int i, j;
	unsigned long key = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			key = key * 10 + mat[i][j];
		}
	}

	return key;
}

void do_bfs()
{
	int i, j;
	unsigned long key;

	l = 0; r = 1;

	while (l < r)
	{
		if (q[l].x > 0)
		{
			memcpy(q + r, q + l, sizeof(STATE));
			
			q[r].mat[q[l].x][q[l].y] = q[r].mat[q[l].x - 1][q[l].y];
			q[r].mat[q[l].x - 1][q[l].y] = 0;

			key = calc_key(q[r].mat);

			if ((existed.find(key)) == (existed.end()))
			{
				q[r].step[(q[r].c)++] = 'D';
				q[r].x = q[l].x - 1;
				q[r++].y = q[l].y;

				existed.insert(key);
			}
		}

		if (q[l].y > 0)
		{
			memcpy(q + r, q + l, sizeof(STATE));

			q[r].mat[q[l].x][q[l].y] = q[r].mat[q[l].x][q[l].y - 1];
			q[r].mat[q[l].x][q[l].y - 1] = 0;

			key = calc_key(q[r].mat);

			if ((existed.find(key)) == (existed.end()))
			{
				q[r].step[(q[r].c)++] = 'R';
				q[r].x = q[l].x;
				q[r++].y = q[l].y - 1;

				existed.insert(key);
			}
		}
		
		if (q[l].y < 2)
		{
			memcpy(q + r, q + l, sizeof(STATE));

			q[r].mat[q[l].x][q[l].y] = q[r].mat[q[l].x][q[l].y + 1];
			q[r].mat[q[l].x][q[l].y + 1] = 0;

			key = calc_key(q[r].mat);

			if ((existed.find(key)) == (existed.end()))
			{
				q[r].step[(q[r].c)++] = 'L';
				q[r].x = q[l].x;
				q[r++].y = q[l].y + 1;

				existed.insert(key);
			}
		}

		if (q[l].x < 2)
		{
			memcpy(q + r, q + l, sizeof(STATE));

			q[r].mat[q[l].x][q[l].y] = q[r].mat[q[l].x + 1][q[l].y];
			q[r].mat[q[l].x + 1][q[l].y] = 0;

			key = calc_key(q[r].mat);

			if ((existed.find(key)) == (existed.end()))
			{
				q[r].step[(q[r].c)++] = 'U';
				q[r].x = q[l].x + 1;
				q[r++].y = q[l].y;

				existed.insert(key);
			}
		}

		l++;
	}
}

int main(int argc, char **argv)
{
	int cas;
	int i, j;
	unsigned long key = 0;

	scanf("%d", &num_case);

	for (cas = 1; cas <= num_case; cas++)
	{
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				scanf("%d", &(q[0].mat[i][j]));

				key = key * 10 + q[0].mat[i][j];

				if (!(q[0].mat[i][j]))
				{
					q[0].x = i;
					q[0].y = j;
				}
			}
		}

		q[0].c = 0;
		existed.clear();
		existed.insert(key);

		do_bfs();

		printf("Puzzle #%d\n", cas);

		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				printf("%d", q[r - 1].mat[i][j]);

				if (j < 2)
				{
					printf(" ");
				}
			}

			printf("\n");
		}

		for (i = 0; i < q[r - 1].c; i++)
		{
			printf("%c", q[r - 1].step[i]);
		}

		printf("\n\n");
	}
	return 0;
}
