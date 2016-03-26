#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int num_case;

int main(int argc, char **argv)
{
	int cas;
	int x;
	int i;

	scanf("%d", &num_case);

	for (cas = 0; cas < num_case; cas++)
	{
		scanf("%d", &x);

		x = abs(x);

		if (!x)
		{
			printf("3\n");
		}
		else
		{
			for (i = sqrt(x); (((((i + 1) * i) / 2) < x) || 
					(((((i + 1) * i) / 2) - x) % 2)); i++);

			printf("%d\n", i);
		}

		if (cas < num_case - 1)
		{
			printf("\n");
		}
	}
}
