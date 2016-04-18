#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compar(const void *a, const void *b)
{
	long aa = *((long *)a), bb = *((long *)b);

	if (aa < bb)
	{
		return -1;
	}
	else if (aa == bb)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

long a[3];

int main(int argc, char **argv)
{
	long aa, bb, cc;

	while (scanf("%ld %ld %ld", a, a + 1, a + 2) == 3)
	{
		if ((!a[0]) && (!a[1]) && (!a[2]))
		{
			break;
		}

		qsort(a, 3, sizeof(long), compar);

		aa = a[0] * a[0];
		bb = a[1] * a[1];
		cc = a[2] * a[2];

		if (aa + bb == cc)
		{
			printf("right\n");
		}
		else
		{
			printf("wrong\n");
		}
	}

	return 0;
}
