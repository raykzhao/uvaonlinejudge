#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char **argv)
{
	int x;
	int cas;
	for (cas = 1; scanf("%d", &x) == 1; cas++)
	{
		if (x < 0)
		{
			break;
		}

		printf("Case %d: %d\n", cas, (int)(ceil(log(x) / log(2))));
	}

	return 0;
}
