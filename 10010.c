#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int num_case;
int m, n;
char grid[100][100];
char str[100];

int compar(int x, int y, int dx, int dy)
{
	int i;
	int flag = 1;

	for (i = 0; (i < strlen(str)) && (x >= 0) && (x < m) && (y >= 0) && (y < n); i++, x += dx, y += dy)
	{
		if (grid[x][y] != str[i])
		{
			flag = 0;
			break;
		}
	}
	
	if (str[i])
	{
		flag = 0;
	}
	
	return flag;
}

void query()
{
	int i, j;
	int flag;
	
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			flag = compar(i, j, -1, -1) | compar(i, j, -1, 0) | compar(i, j, -1, 1) | compar(i, j, 0, -1) | compar(i, j, 0, 1) | compar(i, j, 1, -1) | compar(i, j, 1, 0) | compar(i, j, 1, 1);
			
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
	
	printf("%d %d\n", i + 1, j + 1);
}

int main(int argc, char **argv)
{
	int cas;
	int i, j, k;
	
	scanf("%d", &num_case);
	
	for (cas = 0; cas < num_case; cas++)
	{
		gets(grid[0]);
		
		scanf("%d %d", &m, &n);
		getchar();
		
		for (i = 0; i < m; i++)
		{
			gets(grid[i]);
			
			for (j = 0; j < strlen(grid[i]); j++)
			{
				if ((grid[i][j] >= 'a') && (grid[i][j] <= 'z'))
				{
					grid[i][j] -= 32;
				}
			}
		}
		
		scanf("%d", &k);
		getchar();
		
		for (i = 0; i < k; i++)
		{
			gets(str);

			for (j = 0; j < strlen(str); j++)
			{
				if ((str[j] >= 'a') && (str[j] <= 'z'))
				{
					str[j] -= 32;
				}
			}
			
			query();
		}
		
		if (cas < num_case - 1)
		{
			printf("\n");
		}
	}
	
	return 0;
}
