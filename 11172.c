#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int num_case;

int main(int argc, char **argv)
{
	int cas;
	int x, y;

	scanf("%d", &num_case);

	for (cas = 0; cas < num_case; cas++)
	{
		scanf("%d %d", &x, &y);

		if (x < y)
		{
			printf("<\n");
		}
		else if (x == y)
		{
			printf("=\n");
		}
		else
		{
			printf(">\n");
		}
	}

	return 0;
}
