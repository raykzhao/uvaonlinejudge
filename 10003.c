#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int l, n;
int pos[55];
int price[55][55];

void dp(int x, int y)
{
	int k;
	int min = INT_MAX;
	
	if (x + 1 == y)
	{
		price[x][y] = 0;
		return;
	}
	
	for (k = x + 1; k < y; k++)
	{
		if (price[x][k] == -1)
		{
			dp(x, k);
		}
		
		if (price[k][y] == -1)
		{
			dp(k, y);
		}
		
		if (price[x][k] + price[k][y] + pos[y] - pos[x] < min)
		{
			min = price[x][k] + price[k][y] + pos[y] - pos[x];
		}
	}
	
	price[x][y] = min;
}

int main(int argc, char **argv)
{
	int i, j;
	
	scanf("%d", &l);
	
	while (l)
	{
		scanf("%d", &n);
		
		for (i = 0; i < n + 2; i++)
		{
			pos[i] = 0;
			
			for (j = 0; j < n + 2; j++)
			{
				price[i][j] = -1;
			}
		}
		
		pos[0] = 0;
		
		for (i = 1; i <= n; i++)
		{
			scanf("%d", pos + i);
		}
		
		pos[n + 1] = l;
		
		dp(0, n + 1);
		
		printf("The minimum cutting is %d.\n", price[0][n + 1]);
		
		scanf("%d", &l);
	}
	
	return 0;
}
