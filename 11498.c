#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	int k, n, m;
	int i;
	int x, y;
	
	scanf("%d", &k);
	
	while (k)
	{
		scanf("%d %d", &n, &m);
		
		for (i = 0; i < k; i++)
		{
			scanf("%d %d", &x, &y);
			if ((x == n) || (y == m))
			{
				printf("divisa\n");
			}
			else if ((x < n) && (y < m))
			{
				printf("SO\n");
			}
			else if ((x > n) && (y < m))
			{
				printf("SE\n");
			}
			else if ((x < n) && (y > m))
			{
				printf("NO\n");
			}
			else if ((x > n) && (y > m))
			{
				printf("NE\n");
			}
		}
		
		scanf("%d", &k);
	}
		
	return 0;
}
