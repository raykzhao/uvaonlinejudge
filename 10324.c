#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[1000005];

int main(int argc, char **argv)
{
	int ch;
	int len;
	int n;
	int x, y;
	int i, j;
	int c = 1;
	int flag;
	
	while (gets(str))
	{
		printf("Case %d:\n", c++);
		
		scanf("%d", &n);
		
		for (i = 0; i < n; i++)
		{
			scanf("%d %d", &x, &y);
			if (x > y)
			{
				len = x; x = y; y = len;
			}
			flag = 0;
			for (j = x; j <= y; j++)
			{
				if (str[j] != str[x])
				{
					flag = 1;
					break;
				}
			}
			if (flag)
				printf("No\n");
			else
				printf("Yes\n");
		}

		getchar();
	}
	return 0;
}
