#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	int num_case;
	int cas;
	int n;
	int i;
	int x, y;
	int hi, lo;

	scanf("%d", &num_case);

	for (cas = 1; cas <= num_case; cas++)
	{
		scanf("%d", &n);

		hi = 0; lo = 0;
		scanf("%d", &x);
		for (i = 1; i < n; i++)
		{
			scanf("%d", &y);

			if (y > x)
			{
				hi++;
			}
			if (y < x)
			{
				lo++;
			}

			x = y;
		}

		printf("Case %d: %d %d\n", cas, hi, lo);
	}
	
	return 0;
}
