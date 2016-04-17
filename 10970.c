#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	int m, n;
	long sum;

	while (scanf("%d %d", &m, &n) == 2)
	{
		sum = ((long)m) * ((long)n) - ((long)1);
		printf("%ld\n", sum);
	}

	return 0;
}
