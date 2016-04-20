#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <set>

using namespace std;

multiset <long> price;

int main(int argc, char **argv)
{
	int n;
	
	while (scanf("%d", &n) == 1)
	{
		price.clear();

		for (int i = 0; i < n; i++)
		{
			long x;
			scanf("%ld", &x);

			price.insert(x);
		}

		long m;
		scanf("%ld", &m);

		long a;
		long dif = 1100000;
		for (multiset <long>::iterator it = price.begin(); it != price.end(); it++)
		{
			multiset <long>::iterator it2 = price.find(m - (*it));

			if ((it2 != price.end()) && (it2 != it))
			{
				if (labs(m - (*it) - (*it)) < dif)
				{
					a = *it;
					dif = labs(m - (*it) - (*it));
				}
			}
		}

		long b = m - a;
		if (a > b)
		{
			long t = a; a = b; b = t;
		}

		printf("Peter should buy books whose prices are %ld and %ld.\n", a, b);
		printf("\n");
	}

	return 0;
}
