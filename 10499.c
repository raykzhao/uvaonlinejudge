#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	long n;

	while (scanf("%ld", &n) == 1)
	{
		if (n < 0)
		{
			break;
		}

		if (n == 1)
		{
			printf("0%%\n");
		}
		else
		{
			printf("%lld%%\n", ((long long)25) * ((long long)n));
		}
	}

	return 0;
}
