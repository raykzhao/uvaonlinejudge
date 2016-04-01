#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

using namespace std;

vector <long> num[1000010];

int main(int argc, char **argv)
{
	long n, m;

	while (scanf("%ld %ld", &n, &m) == 2)
	{
		for (long i = 0; i <= 1000000; i++)
		{
			num[i].clear();
		}

		for (long i = 1; i <= n; i++)
		{
			long x;
			scanf("%ld", &x);

			num[x].push_back(i);
		}

		for (long i = 0; i < m; i++)
		{
			long x, y;
			scanf("%ld %ld", &y, &x);
			y--;

			if (y < num[x].size())
			{
				printf("%ld\n", num[x][y]);
			}
			else
			{
				printf("0\n");
			}
		}
	}

	return 0;
}
