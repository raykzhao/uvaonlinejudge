#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long long s[1000010];

int main(int argc, char **argv)
{
	long i;
	long n;
	long long t;

	for (i = 1; i <= 1000000; i++)
	{
		t = 2 * i - 1;
		t *= t;

		s[i] = s[i - 1] + t;
	}

	while (scanf("%ld", &n) == 1)
	{
		if (!n)
		{
			break;
		}

		t = n;
		t = t * t * t;

		printf("%.6f\n", sqrt((s[n] - t) / (n - 1.0)));
	}

	return 0;
}
