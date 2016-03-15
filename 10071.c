#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	int v, t;

	while (scanf("%d %d", &v, &t) == 2)
	{
		printf("%d\n", 2 * v * t);
	}

	return 0;
}
