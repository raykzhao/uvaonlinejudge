#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>

using namespace std;

queue <long> q[2];

int numCase;
long ferry;
char str[10];

void do_trans()
{
	long count = 0;
	int side = 0;

	while ((!q[0].empty()) || (!q[1].empty()))
	{
		long load = 0;
		while (!q[side].empty())
		{
			if (load + q[side].front() <= ferry)
			{
				load += q[side].front();
				q[side].pop();
			}
			else
			{
				break;
			}
		}

		side ^= 1;
		count++;
	}

	printf("%ld\n", count);
}

int main(int argc, char **argv)
{
	scanf("%d", &numCase);

	for (int cas = 0; cas < numCase; cas++)
	{
		long m;
		scanf("%ld %ld", &ferry, &m);
		ferry *= (long)100;

		for (long i = 0; i < m; i++)
		{
			long x;
			scanf("%ld %s", &x, str);

			if (!strcmp(str, "left"))
			{
				q[0].push(x);
			}
			else if (!strcmp(str, "right"))
			{
				q[1].push(x);
			}
		}

		do_trans();
	}

	return 0;
}
