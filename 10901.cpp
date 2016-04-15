#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <utility>

using namespace std;

queue < pair <long, int> > q[2];

int numCase;
int n, t;
char str[10];
long trans[10010];

pair <long, int> queueMin(pair <long, int> x, pair <long, int> y, int curSide)
{
	if (x.first < y.first)
	{
		return make_pair(x.first, 0);
	}
	else if (x.first == y.first)
	{
		return make_pair(x.first, curSide);
	}
	else
	{
		return make_pair(y.first, 1);
	}
}

void do_trans()
{
	long curTime = 0;
	int curSide = 0;

	while ((!(q[0].empty())) || (!(q[1].empty())))
	{
		pair <long, int> comp1, comp2;
		if (q[0].empty())
		{
			comp1 = make_pair(2000000000, 0);
		}
		else
		{
			comp1 = q[0].front();
		}

		if (q[1].empty())
		{
			comp2 = make_pair(2000000000, 0);
		}
		else
		{
			comp2 = q[1].front();
		}

		pair <long, int> curMin = queueMin(comp1, comp2, curSide);
		if (curTime <= curMin.first)
		{
			curTime = curMin.first;
			if (curSide != curMin.second)
			{
				curSide = curMin.second;
				curTime += (long)t;
			}
		}

			int count = 0;
			while (!q[curSide].empty())
			{
				if (((q[curSide].front()).first <= curTime) && ((count++) < n))
				{
					trans[(q[curSide].front()).second] = curTime + ((long)t);
					q[curSide].pop();
				}
				else
				{
					break;
				}
			}

		curTime += (long)t;
		curSide ^= 1;
	}
}

int main(int argc, char **argv)
{
	scanf("%d", &numCase);

	for (int cas = 0; cas < numCase; cas++)
	{
		int m;
		scanf("%d %d %d", &n, &t, &m);

		for (int i = 0; i < m; i++)
		{
			long x;
			scanf("%ld %s", &x, str);
		
			if (!strcmp(str, "left"))
			{
				q[0].push(make_pair(x, i));
			}
			else if (!strcmp(str, "right"))
			{
				q[1].push(make_pair(x, i));
			}
		}

		memset(trans, 0, sizeof(trans));
		do_trans();

		for (int i = 0; i < m; i++)
		{
			printf("%ld\n", trans[i]);
		}

		if (cas < numCase - 1)
		{
			printf("\n");
		}
	}

	return 0;
}
