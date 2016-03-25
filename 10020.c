#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int line[50010];
int output[50010][2];

int first_x;
int num_case;
int m, n;
int c;

int main(int argc, char **argv)
{
	int cas;
	int x, y, i;
	int l, r, pos;

	scanf("%d", &num_case);

	for (cas = 0; cas < num_case; cas++)
	{
		scanf("%d", &m);

		for (i = 0; i <= m; i++)
		{
			line[i] = -50001;
		}

		n = 0;

		while (1)
		{
			scanf("%d %d", &x, &y);

			if ((!x) && (!y))
			{
				break;
			}

			if (x <= 0)
			{
				if (y > line[0])
				{
					if (line[0] == -50001)
					{
						n++;
					}

					line[0] = y;
					first_x = x;
				}
			}
			else
			{
				if (y > line[x])
				{
					if (line[x] == -50001)
					{
						n++;
					}

					line[x] = y;
				}
			}
		}

		output[0][0] = first_x;
		output[0][1] = line[0];

		l = line[0];
		c = 1;

		while ((l < m) && (c < n))
		{
			pos = -1;
			r = l;

			for (i = 1; i <= l; i++)
			{
				if ((line[i] != -50001) && (line[i] > r))
				{
					pos = i;
					r = line[i];
				}
			}

			if (pos < 0)
			{
				break;
			}

			output[c][0] = pos;
			output[c++][1] = r;

			l = r;
		}

		if (l < m)
		{
			printf("0\n");
		}
		else
		{
			printf("%d\n", c);

			for (i = 0; i < c; i++)
			{
				printf("%d %d\n", output[i][0], output[i][1]);
			}
		}

		if (cas < num_case - 1)
		{
			printf("\n");
		}
	}

	return 0;
}
