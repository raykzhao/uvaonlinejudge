#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>

using namespace std;

priority_queue <long> q;

int main(int argc, char **argv)
{
	int n;

	while (1)
	{
		scanf("%d", &n);

		if (!n)
		{
			break;
		}

		for (int i = 0; i < n; i++)
		{
			long x;
			
			scanf("%ld", &x);

			q.push(-x);
		}

		long sum = 0;

		while (1)
		{
			long x = q.top();
			q.pop();
			x += q.top();
			q.pop();

			sum -= x;

			if (q.empty())
			{
				break;
			}
			else
			{
				q.push(x);
			}
		}

		printf("%ld\n", sum);
	}

	return 0;
}
