#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[20];

int main(int argc, char **argv)
{
	int num_case;
	int cas;
	long x;

	scanf("%d", &num_case);

	for (cas = 0; cas < num_case; cas++)
	{
		scanf("%ld", &x);

		x *= (long)567;
		x /= (long)9;
		x += (long)7492;
		x *= (long)235;
		x /= (long)47;
		x -= (long)498;

		sprintf(str, "%ld", x);
		printf("%c\n", str[strlen(str) - 2]);
	}

	return 0;
}
