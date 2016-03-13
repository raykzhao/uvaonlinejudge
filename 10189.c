#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s[105];
int square[105][105];

int main(int argc, char **argv)
{
	int n, m;
	int i, j;
	int k = 0;
	
	while (1)
	{
		scanf("%d %d", &n, &m);
		if ((n == 0) && (m == 0))
		{
			break;
		}
		
		k++;
		
		for (i = 1; i <= n; i++)
			for (j = 1; j <= m; j++)
			{
				square[i][j] = 0;
			}
		
		for (i = 0; i < n; i++)
		{
			scanf("%s", s);
			for (j = 0; j < m; j++)
			{
				if (s[j] == '*')
				{
					square[i + 1][j + 1] = -1000;
				}
			}
		}
		
		for (i = 1; i <= n; i++)
			for (j = 1; j <= m; j++)
			{
				if (square[i][j] < 0)
				{
					square[i - 1][j - 1]++;
					square[i - 1][j]++;
					square[i - 1][j + 1]++;
					square[i][j - 1]++;
					square[i][j + 1]++;
					square[i + 1][j - 1]++;
					square[i + 1][j]++;
					square[i + 1][j + 1]++;					
				}
			}
		
		if (k != 1)
		{
			printf("\n");
		}

		printf("Field #%d:\n", k); 
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= m; j++)
			{
				if (square[i][j] < 0)
				{
					putchar('*');
				}
				else
				{
					printf("%d", square[i][j]);
				}
			}
			printf("\n");
		}
	}
	return 0;
}
