#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	int num_case;
	int cas;
	int x, y, z;

	scanf("%d", &num_case);
	for (cas = 1; cas <= num_case; cas++)
	{
		scanf("%d %d %d", &x, &y, &z);

		printf("Case %d: ", cas);
		if (x <= 20 && y <= 20 && z <= 20)
		{
			printf("good\n");
		}
		else
		{
			printf("bad\n");
		}
	}

	return 0;
}
