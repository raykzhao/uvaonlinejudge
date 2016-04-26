#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack>
#include <queue>

using namespace std;

stack <long> stk;
queue <long> q;
priority_queue <long> pq;

int main(int argc, char **argv)
{
	int n;

	while (scanf("%d", &n) == 1)
	{
		stk = stack <long> ();
		q = queue <long> ();
		pq = priority_queue <long> ();

		int isStk = 1;
		int isQ = 1;
		int isPQ = 1;

		for (int i = 0; i < n; i++)
		{
			long x, y;
			scanf("%ld %ld", &x, &y);

			switch (x)
			{
				case 1:
					stk.push(y);
					q.push(y);
					pq.push(y);
					break;
				case 2:
					if (stk.empty())
					{
						isStk = 0;
					}
					else
					{
						if (stk.top() != y)
						{
							isStk = 0;
						}
						stk.pop();
					}

					if (q.empty())
					{
						isQ = 0;
					}
					else
					{
						if (q.front() != y)
						{
							isQ = 0;
						}
						q.pop();
					}

					if (pq.empty())
					{
						isPQ = 0;
					}
					else
					{
						if (pq.top() != y)
						{
							isPQ = 0;
						}
						pq.pop();
					}
			}
		}

		if (!(isStk + isQ + isPQ))
		{
			puts("impossible");
		}
		else if (isStk + isQ + isPQ > 1)
		{
			puts("not sure");
		}
		else
		{
			if (isStk)
			{
				puts("stack");
			}
			
			if (isQ)
			{
				puts("queue");
			}

			if (isPQ)
			{
				puts("priority queue");
			}
		}
	}
	
	return 0;
}
