#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	int num_case;
	int cas;
	int a, b;
	int sum;
	int i;

	scanf("%d", &num_case);

	for (cas = 1; cas <= num_case; cas++)
	{
		scanf("%d %d", &a, &b);
		
		sum = 0;
		for (i = a; i <= b; i++)
		{
			if (i % 2)
			{
				sum += i;
			}
		}

		printf("Case %d: %d\n", cas, sum);
	}

	return 0;
}
