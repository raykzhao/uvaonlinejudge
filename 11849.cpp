#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <set>

using namespace std;

set <long> cd;

int main(int argc, char **argv)
{
	while (1)
	{
		long n, m;
		scanf("%ld %ld", &n, &m);

		if ((!n) && (!m))
		{
			break;
		}

		cd.clear();

		for (long i = 0; i < n; i++)
		{
			long x;
			scanf("%ld", &x);

			cd.insert(x);
		}

		long sum = 0;

		for (long i = 0; i < m; i++)
		{
			long x;
			scanf("%ld", &x);

			if (cd.find(x) != cd.end())
			{
				sum++;
			}
		}

		printf("%ld\n", sum);
	}

	return 0;
}
