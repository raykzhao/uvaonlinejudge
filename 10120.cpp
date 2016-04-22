#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <utility>

using namespace std;

long n, m;

queue < pair <int, int> > q;

int check_pos(int pos, int step)
{
	if (pos == m)
	{
		return 1;
	}

	if ((pos > 0) && (pos <= n))
	{
		q.push(make_pair(pos, step));
	}

	return 0;
}

void do_bfs()
{
	q = queue < pair <int, int> > ();
	q.push(make_pair(1, 1));

	while (!q.empty())
	{
		int cur = (q.front()).first;
		int step = (q.front()).second + 1;
		q.pop();
		
		if ((check_pos(cur - (2 * step - 1), step)) || (check_pos(cur + 2 * step - 1, step)))
		{
			puts("Let me try!");
			return;
		}
	}

	puts("Don't make fun of me!");
}

int main(int argc, char **argv)
{
	while (scanf("%ld %ld", &n, &m) == 2)
	{
		if ((!n) && (!m))
		{
			break;
		}

		if ((n >= 49) || (m == 1))
		{
			puts("Let me try!");
		}
		else
		{
			do_bfs();
		}
	}

	return 0;
}
