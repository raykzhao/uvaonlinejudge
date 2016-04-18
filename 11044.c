#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	int num_case;
	int cas;
	int n, m;

	scanf("%d", &num_case);

	for (cas = 0; cas < num_case; cas++)
	{
		scanf("%d %d", &n, &m);

		if (n > 2)
		{
			n -= 2;
		}
		
		if (m > 2)
		{
			m -= 2;
		}

		if (n % 3)
		{
			n = n / 3 + 1;
		}
		else
		{
			n = n / 3;
		}

		if (m % 3)
		{
			m = m / 3 + 1;
		}
		else
		{
			m = m / 3;
		}

		printf("%ld\n", ((long)n) * ((long)m));
	}

	return 0;
}
