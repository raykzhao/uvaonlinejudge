#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double p, q, r, s, t, u;

double func(double x)
{
	return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

double d_func(double x)
{
	return -p * exp(-x) + q * cos(x) - r * sin(x) + s + s * tan(x) * tan(x) + 2.0 * t * x;
}

void newton()
{
	double x0 = 0.5;
	double x1;

	if (func(0) * func(1) > 0)
	{
		printf("No solution\n");
		return;
	}

	if (func(0) == 0)
	{
		printf("0.0000\n");
		return;
	}

	while (1)
	{
		x1 = x0 - func(x0) / d_func(x0);

		if (fabs(x1 - x0) < 1e-7)
		{
			break;
		}

		x0 = x1;
	}

	printf("%.4f\n", x1);
}

int main(int argc, char **argv)
{
	int pp, qq, rr, ss, tt, uu;

	while (scanf("%d %d %d %d %d %d", &pp, &qq, &rr, &ss, &tt, &uu) == 6)
	{
		p = (double)pp;
		q = (double)qq;
		r = (double)rr;
		s = (double)ss;
		t = (double)tt;
		u = (double)uu;

		newton();
	}

	return 0;
}
