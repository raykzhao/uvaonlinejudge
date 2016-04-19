#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	int num_case;
	int cas;
	int c, d;
	double fahr;

	scanf("%d", &num_case);

	for (cas = 1; cas <= num_case; cas++)
	{
		scanf("%d %d", &c, &d);

		fahr = 9.0 / 5.0 * ((double)c) + 32.0 + ((double)d);
		printf("Case %d: %.2f\n", cas, (fahr - 32.0) * 5.0 / 9.0);
	}

	return 0;
}
