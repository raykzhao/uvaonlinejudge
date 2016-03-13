#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	int t;
	int n, max;
	int i, j;
	int c;
	
	scanf("%d", &t);
	
	for (i = 1; i <= t; i++)
	{
		scanf("%d", &n);
		
		max = 0;
		for (j = 0; j < n; j++)
		{
			scanf("%d", &c);
			if (c > max)
				max = c;
		}
		
		printf("Case %d: %d\n", i, max);
	}
	
	return 0;
}
