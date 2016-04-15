#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <set>
#include <deque>

using namespace std;

set <int> graph[2010];
set <int> reverseGraph[2010];
deque <int> q;
set <int> visited;
int n;

void do_scc_visit(int x)
{
	if (visited.find(x) == visited.end())
	{
		visited.insert(x);

		for (set <int>::iterator it = graph[x].begin(); it != graph[x].end(); it++)
		{
			do_scc_visit(*it);
		}

		q.push_front(x);
	}
}

void do_scc_assign(int x)
{
	visited.insert(x);

	for (set <int>::iterator it = reverseGraph[x].begin(); it != reverseGraph[x].end(); it++)
	{
		if (visited.find(*it) == visited.end())
		{
			do_scc_assign(*it);
		}
	}
}

void do_scc()
{
	visited.clear();
	q.clear();

	for (int i = 1; i <= n; i++)
	{
		do_scc_visit(i);
	}

	visited.clear();
	int sum = 0;
	while (!q.empty())
	{
		int x = q.front();
		if (visited.find(x) == visited.end())
		{
			sum++;
			do_scc_assign(x);
		}
		q.pop_front();
	}

	if (sum == 1)
	{
		printf("1\n");
	}
	else
	{
		printf("0\n");
	}
}

int main(int argc, char **argv)
{
	long m;
	while (scanf("%d %ld", &n, &m) == 2)
	{
		if ((!n) && (!m))
		{
			break;
		}

		for (int i = 1; i <= n; i++)
		{
			graph[i].clear();
			reverseGraph[i].clear();
		}

		for (long i = 0; i < m; i++)
		{
			int x, y, s;
			scanf("%d %d %d", &x, &y, &s);

			graph[x].insert(y);
			reverseGraph[y].insert(x);
			if (s == 2)
			{
				graph[y].insert(x);
				reverseGraph[x].insert(y);
			}
		}

		do_scc();
	}

	return 0;
}
