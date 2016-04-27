#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char **argv)
{
	double pi = 2.0 * acos(0.0);
	int aa, bb, cc;
	double a, b, c;
	double p, pp;
	double c1, tri, c2;

	while (scanf("%d %d %d", &aa, &bb, &cc) == 3)
	{
		a = (double)aa;
		b = (double)bb;
		c = (double)cc;
		p = (a + b + c) / 2.0;
		pp = (p - a) * (p - b) * (p - c);

		c1 = pi * a * a * b * b * c * c / (16.0 * p * pp);
		tri = sqrt(p * pp);
		c2 = 2.0 * pi * pp / (a + b + c);

		printf("%.4f %.4f %.4f\n", c1 - tri, tri - c2, c2);
	}

	return 0;
}
