#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <utility>

using namespace std;

char prime[20000010];

vector < pair <long, long> > primePair;

void sieve()
{
	prime[0] = 1;
	prime[1] = 1;
	for (long i = 4; i <= 20000000; i += 2)
	{
		prime[i] = 1;
	}

	for (long i = 3; i <= ((long)sqrt(20000000)); i += 2)
	{
		if (!prime[i])
		{
			for (long j = i * i; j <= 20000000; j += ((long)2) * i)
			{
				prime[j] = 1;
			}
		}
	}

	for (long i = 3; i <= 19999998; i += 2)
	{
		if (!prime[i])
		{
			if (!prime[i + 2])
			{
				primePair.push_back(make_pair(i, i + 2));
			}
		}
	}
}

int main(int argc, char **argv)
{
	sieve();

	long n;
	while (scanf("%ld", &n) == 1)
	{
		printf("(%ld, %ld)\n", primePair[n - 1].first, primePair[n - 1].second);
	}

	return 0;
}
