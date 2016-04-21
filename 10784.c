#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char **argv)
{
	long long n;
	int cas;
	for (cas = 1; scanf("%lld", &n) == 1; cas++)
	{
		if (!n)
		{
			break;
		}

		printf("Case %d: %lld\n", cas, (long long)(ceil((3.0 + sqrt(9.0 + 8.0 * ((double)n))) / 2.0)));
	}

	return 0;
}
