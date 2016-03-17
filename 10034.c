#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct xy
{
	double x, y;
} XY;

typedef struct edge
{
	int u, v;
	double w;
} EDGE;

typedef struct disjoint
{
	int parent, rank;
} DISJOINT;

int num_case;
int v;
int e;

XY verticle[110];
EDGE graph[10010];
DISJOINT set[110];

int compar(const void *a, const void *b)
{
	EDGE aa = *((EDGE *)a), bb = *((EDGE *)b);

	if (aa.w < bb.w)
	{
		return -1;
	}
	else if (aa.w == bb.w)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int disjoint_find(int x)
{
	if (set[x].parent != x)
	{
		set[x].parent = disjoint_find(set[x].parent);
	}

	return (set[x].parent);
}

void disjoint_union(int x, int y)
{
	int xRoot = disjoint_find(x);
	int yRoot = disjoint_find(y);

	if (xRoot == yRoot)
	{
		return;
	}

	if (set[xRoot].rank < set[yRoot].rank)
	{
		set[xRoot].parent = yRoot;
	}
	else if (set[xRoot].rank > set[yRoot].rank)
	{
		set[yRoot].parent = xRoot;
	}
	else
	{
		set[yRoot].parent = xRoot;
		(set[xRoot].rank)++;
	}
}

void kruskal()
{
	double length = 0;
	int i;
	
	for (i = 0; i < v; i++)
	{
		set[i].parent = i;
		set[i].rank = 0;
	}

	for (i = 0; i < e; i++)
	{
		if (disjoint_find(graph[i].u) != disjoint_find(graph[i].v))
		{
			length += graph[i].w;
			disjoint_union(graph[i].u, graph[i].v);
		}
	}

	printf("%.2f\n", length);
}

int main(int argc, char **argv)
{
	int cas;
	int i, j;
	double x, y, dist;

	scanf("%d", &num_case);

	for (cas = 0; cas < num_case; cas++)
	{
		scanf("%d", &v);

		e = 0;

		for (i = 0; i < v; i++)
		{
			scanf("%lf %lf", &(verticle[i].x), &(verticle[i].y));

			for (j = 0; j < i; j++)
			{
				dist = sqrt((verticle[i].x - verticle[j].x) * 
							(verticle[i].x - verticle[j].x) +
							(verticle[i].y - verticle[j].y) *
							(verticle[i].y - verticle[j].y));

				graph[e].u = i;
				graph[e].v = j;
				graph[e++].w = dist;
			}
		}

		qsort(graph, e, sizeof(EDGE), compar);

		kruskal();

		if (cas < (num_case - 1))
		{
			printf("\n");
		}
	}

	return 0;
}
