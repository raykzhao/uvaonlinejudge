#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	unsigned long a, b;

	while (scanf("%lu %lu", &a, &b) == 2)
	{
		printf("%lu\n", a ^ b);
	}

	return 0;
}
