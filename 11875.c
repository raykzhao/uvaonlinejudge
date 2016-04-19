#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	int num_case;
	int cas;
	int n;
	int i;
	int x;

	scanf("%d", &num_case);

	for (cas = 1; cas <= num_case; cas++)
	{
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			scanf("%d", &x);
			if (i == n / 2)
			{
				printf("Case %d: %d\n", cas, x);
			}
		}
	}

	return 0;
}
