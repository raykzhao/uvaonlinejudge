#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct set
{
	long parent;
	long rank;
} SET;

typedef struct edge
{
	long x, y;
	long dist;
} EDGE;

SET disjoint[200010];
EDGE graph[200010];

long m, n;

void make_set(long x)
{
	disjoint[x].parent = x;
	disjoint[x].rank = 0;
}

long find(long x)
{
	if (disjoint[x].parent != x)
	{
		disjoint[x].parent = find(disjoint[x].parent);
	}

	return disjoint[x].parent;
}

void make_union(long x, long y)
{
	long x_root = find(x);
	long y_root = find(y);

	if (x_root == y_root)
	{
		return;
	}

	if (disjoint[x_root].rank < disjoint[y_root].rank)
	{
		disjoint[x_root].parent = y_root;
	}
	else if (disjoint[x_root].rank > disjoint[y_root].rank)
	{
		disjoint[y_root].parent = x_root;
	}
	else
	{
		disjoint[y_root].parent = x_root;
		(disjoint[x_root].rank)++;
	}
}

long kruskal()
{
	long i;
	long sum = 0;

	for (i = 0; i < m; i++)
	{
		make_set(i);
	}

	for (i = 0; i < n; i++)
	{
		if (find(graph[i].x) != find(graph[i].y))
		{
			sum += graph[i].dist;
			make_union(graph[i].x, graph[i].y);
		}
	}

	return sum;
}

int compar(const void *a, const void *b)
{
	EDGE aa = *((EDGE *)a), bb = *((EDGE *)b);

	if (aa.dist < bb.dist)
	{
		return -1;
	}
	else if (aa.dist == bb.dist)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int main(int argc, char **argv)
{
	long i;
	long total;

	while (scanf("%ld %ld", &m, &n) == 2)
	{
		if ((!m) && (!n))
		{
			break;
		}

		total = 0;
		for (i = 0; i < n; i++)
		{
			scanf("%ld %ld %ld", &(graph[i].x), &(graph[i].y), &(graph[i].dist));
			total += graph[i].dist;
		}

		qsort(graph, n, sizeof(EDGE), compar);

		printf("%ld\n", total - kruskal());
	}

	return 0;
}
