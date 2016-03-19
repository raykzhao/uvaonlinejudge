#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int num_case;
int n;
int graph[110][110];
int x_top, x_bottom, y_left, y_right;

void transform1()
{
	int i;
	int x;

	for (i = y_left; i <= y_right; i++)
	{
		x = graph[x_top][i];
		graph[x_top][i] = graph[x_bottom][i];
		graph[x_bottom][i] = x;
	}

	for (i = x_top + 1; i < (n / 2); i++)
	{
		x = graph[i][y_left];
		graph[i][y_left] = graph[n - 1 - i][y_left];
		graph[n - 1 - i][y_left] = x;

		x = graph[i][y_right];
		graph[i][y_right] = graph[n - 1 - i][y_right];
		graph[n - 1 - i][y_right] = x;
	}
}

void transform2()
{
	int i;
	int x;

	for (i = x_top; i <= x_bottom; i++)
	{
		x = graph[i][y_left];
		graph[i][y_left] = graph[i][y_right];
		graph[i][y_right] = x;
	}

	for (i = y_left + 1; i < (n / 2); i++)
	{
		x = graph[x_top][i];
		graph[x_top][i] = graph[x_top][n - 1 - i];
		graph[x_top][n - 1 - i] = x;

		x = graph[x_bottom][i];
		graph[x_bottom][i] = graph[x_bottom][n - 1 - i];
		graph[x_bottom][n - 1 - i] = x;
	}
}

void transform4()
{
	int i;
	int x;

	for (i = x_top; i < x_bottom; i++)
	{
		x = graph[i][y_left];
		graph[i][y_left] = graph[x_bottom][y_right - (i - x_top)];
		graph[x_bottom][y_right - (i - x_top)] = x;
	}

	for (i = y_left + 1; i < y_right; i++)
	{
		x = graph[x_top][i];
		graph[x_top][i] = graph[x_bottom - (i - y_left)][y_right];
		graph[x_bottom - (i - y_left)][y_right] = x;
	}
}

void transform3()
{
	int i;
	int x;

	for (i = x_top + 1; i <= x_bottom; i++)
	{
		x = graph[i][y_left];
		graph[i][y_left] = graph[x_top][y_left + (i - x_top)];
		graph[x_top][y_left + (i - x_top)] = x;
	}

	for (i = y_left + 1; i < y_right; i++)
	{
		x = graph[x_bottom][i];
		graph[x_bottom][i] = graph[x_top + (i - y_left)][y_right];
		graph[x_top + (i - y_left)][y_right] = x;
	}
}

int main(int argc, char **argv)
{
	int cas;
	int i, j;
	int t, c;

	scanf("%d", &num_case);
	
	for (cas = 0; cas < num_case; cas++)
	{
		scanf("%d", &n);
	
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				scanf("%d", &(graph[i][j]));
			}
		}

		for (i = ((n + 1) / 2) - 1; i >= 0; i--)
		{
			scanf("%d", &t);
			
			if (n % 2)
			{
				x_top = (n / 2) - i;
				x_bottom = (n / 2) + i;
				y_left = (n / 2) - i;
				y_right = (n / 2) + i;
			}
			else
			{
				x_top = (n / 2) - 1 - i;
				x_bottom = (n / 2) + i;
				y_left = (n / 2) - 1 - i;
				y_right = (n / 2) + i;
			}

			for (j = 0; j < t; j++)
			{
				scanf("%d", &c);

				switch (c)
				{
					case 1:
						transform1();
						break;
					case 2:
						transform2();
						break;
					case 3:
						transform3();
						break;
					case 4:
						transform4();
						break;
					default:
						break;
				}
			}
		}

		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				printf("%d", graph[i][j]);
				
				if (j < n - 1)
				{
					printf(" ");
				}
			}
			printf("\n");
		}
	}

	return 0;
}
