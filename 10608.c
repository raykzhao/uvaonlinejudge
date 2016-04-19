#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct disjoint
{
	long parent, size;
} DISJOINT;

DISJOINT friends[30010];

void make_set(long x)
{
	friends[x].parent = x;
	friends[x].size = 1;
}

long set_find(long x)
{
	if (friends[x].parent != x)
	{
		friends[x].parent = set_find(friends[x].parent);
	}

	return friends[x].parent;
}

void set_union(long x, long y)
{
	long x_father = set_find(x), y_father = set_find(y);

	if (x_father == y_father)
	{
		return;
	}

	if (friends[x_father].size < friends[y_father].size)
	{
		friends[x_father].parent = y_father;
		friends[y_father].size += friends[x_father].size;
	}
	else
	{
		friends[y_father].parent = x_father;
		friends[x_father].size += friends[y_father].size;
	}
}

int main(int argc, char **argv)
{
	int num_case;
	long n, m;
	int cas;
	long i;
	long x, y;
	long max;

	scanf("%d", &num_case);
	for (cas = 0; cas < num_case; cas++)
	{
		scanf("%ld %ld", &n, &m);

		for (i = 1; i <= n; i++)
		{
			make_set(i);
		}

		for (i = 0; i < m; i++)
		{
			scanf("%ld %ld", &x, &y);
			set_union(x, y);
		}

		max = 0;
		for (i = 1; i <= n; i++)
		{
			if (friends[i].size > max)
			{
				max = friends[i].size;
			}
		}

		printf("%ld\n", max);
	}

	return 0;
}
