#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char **argv)
{
	double a, b, c;
	double p;
	double r;

	while (scanf("%lf %lf %lf", &a, &b, &c) == 3)
	{
		p = (a + b + c) / 2.0;
		r = (p - a) * (p - b) * (p - c);

		if (r <= 0)
		{
			r = 0;
		}
		else
		{
			r = sqrt(r / p);
		}
		printf("The radius of the round table is: %.3f\n", r);
	}
	
	return 0;
}
