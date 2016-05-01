#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long min(long a, long b)
{
	return (a < b) ? a : b;
}

int main(int argc, char **argv)
{
	int n;
	long b;
	int h;
	int w;
	int i;
	long ans;
	long price;
	int bed;
	int j;
	int flag;

	while (scanf("%d %ld %d %d", &n, &b, &h, &w) == 4)
	{
		ans = 1000000;

		for (i = 0; i < h; i++)
		{
			scanf("%ld", &price);
			
			flag = 0;
			for (j = 0; j < w; j++)
			{
				scanf("%d", &bed);
				if (bed >= n)
				{
					flag = 1;
				}
			}

			if ((flag) && (((long)n) * price <= b))
			{
				ans = min(ans, ((long)n) * price);
			}
		}

		if (ans > b)
		{
			puts("stay home");
		}
		else
		{
			printf("%ld\n", ans);
		}
	}

	return 0;
}
