#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <set>

using namespace std;

multiset <long> bet;

int main(int argc, char **argv)
{
	long n;
	
	while (1)
	{
		long sum = 0;

		scanf("%ld", &n);

		if (!n)
		{
			break;
		}

		bet.clear();

		for (long day = 0; day < n; day++)
		{
			long k;
			scanf("%ld", &k);

			for (long i = 0; i < k; i++)
			{
				long x;
				scanf("%ld", &x);

				bet.insert(x);
			}

			multiset <long>::iterator st = bet.begin();
			multiset <long>::iterator ed = bet.end();
			ed--;

			sum += *ed - *st;
			bet.erase(ed);
			bet.erase(st);
		}

		printf("%ld\n", sum);
	}

	return 0;
}
