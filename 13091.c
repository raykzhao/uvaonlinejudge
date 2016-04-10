#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char grid[10][10];
char str[10];

int num_case;

int main(int argc, char **argv)
{
	int cas;
	int i;
	int j;
	int line;
	int find;

	scanf("%d", &num_case);
	getchar();

	for (cas = 1; cas <= num_case; cas++)
	{
		for (i = 0; i < 5; i++)
		{
			gets(grid[i]);
		}
		gets(str);

		for (line = 0; line < 5 && grid[0][line] != '|'; line++);

		find = 0;
		for (i = 0; i < 5; i++)
		{
			for (j = 0; j < 5; j++)
			{
				if ((grid[i][j] == '>') || (grid[i][j] == '<'))
				{
					find = 1;
					break;
				}
			}

			if (find)
			{
				break;
			}
		}

		printf("Case %d: ", cas);
		if (((grid[i][j] == '>') && (j > line)) || ((grid[i][j] == '<') && (j < line)))
		{
			printf("No Ball\n");
		}
		else
		{
			printf("Thik Ball\n");
		}
	}

	return 0;
}
