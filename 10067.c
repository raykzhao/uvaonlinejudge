#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int num_case;

int step[10010];

int queue[10010];

int st, ed;

void do_bfs()
{
	int l = 0, r = 1;
	int digit[4];
	int i;
	int tmp, new;

	if (step[st] < 0)
	{
		return;
	}

	queue[l] = st;

	while (l < r)
	{
		if (step[ed] != 20000)
		{
			break;
		}

		digit[0] = queue[l] / 1000;
		digit[1] = (queue[l] / 100) % 10;
		digit[2] = (queue[l] / 10) % 10;
		digit[3] = queue[l] % 10;

		for (i = 0; i < 4; i++)
		{
			tmp = digit[i];

			digit[i] = (tmp + 1) % 10;
			new = digit[0] * 1000 + digit[1] * 100 + digit[2] * 10 + digit[3];

			if (step[queue[l]] + 1 < step[new])
			{
				step[new] = step[queue[l]] + 1;

				queue[r++] = new;
			}

			digit[i] = tmp - 1;
			if (digit[i] < 0)
			{
				digit[i] = 9;
			}

			new = digit[0] * 1000 + digit[1] * 100 + digit[2] * 10 + digit[3];

			if (step[queue[l]] + 1 < step[new])
			{
				step[new] = step[queue[l]] + 1;

				queue[r++] = new;
			}

			digit[i] = tmp;
		}

		l++;
	}
}

int main(int argc, char **argv)
{
	int cas;
	int i, n;
	int a, b, c, d;

	scanf("%d", &num_case);

	for (cas = 0; cas < num_case; cas++)
	{
		for (i = 0; i <= 9999; i++)
		{
			step[i] = 20000;
		}

		scanf("%d %d %d %d", &a, &b, &c, &d);
		st = a * 1000 + b * 100 + c * 10 + d;
		step[st] = 0;

		scanf("%d %d %d %d", &a, &b, &c, &d);
		ed = a * 1000 + b * 100 + c * 10 + d;

		scanf("%d", &n);

		for(i = 0; i < n; i++)
		{
			scanf("%d %d %d %d", &a, &b, &c, &d);
			step[a * 1000 + b * 100 + c * 10 + d] = -1;
		}

		do_bfs();

		if ((step[ed] >= 0) && (step[ed] != 20000))
		{
			printf("%d\n", step[ed]);
		}
		else
		{
			printf("-1\n");
		}
	}

	return 0;
}
