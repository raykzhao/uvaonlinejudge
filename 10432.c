#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char **argv)
{
	double pi = 2.0 * acos(0);
	double r;
	long n;

	while (scanf("%lf %ld", &r, &n) == 2)
	{
		printf("%.3f\n", 0.5 * r * r * sin(2.0 * pi / ((double)n)) * ((double)n));
	}

	return 0;
}
