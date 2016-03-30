#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char **argv)
{
	unsigned long n;
	unsigned long x;

	while (1)
	{
		scanf("%lu", &n);
		
		if (!n)
		{
			break;
		}

		x = (unsigned long)(sqrt(n));

		if (x * x == n)
		{
			printf("yes\n");
		}
		else
		{
			printf("no\n");
		}
	}

	return 0;
}
