#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct vote
{
	int index;
	long long v;
} VOTE;

VOTE candidate[510];
double percentage[510];

int compar(const void *a, const void *b)
{
	VOTE aa = *((VOTE *)a), bb = *((VOTE *)b);

	if (aa.v < bb.v)
	{
		return 1;
	}
	else if (aa.v > bb.v)
	{
		return -1;
	}
	else
	{
		if (aa.index < bb.index)
		{
			return -1;
		}
		else if (aa.index == bb.index)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
}

int main(int argc, char **argv)
{
	int num_case;
	int cas;
	int n, m;
	int i;
	int j;
	long long total;
	long long pop;
	int flag;

	scanf("%d", &num_case);
	for (cas = 0; cas < num_case; cas++)
	{
		scanf("%d %d", &n, &m);

		for (i = 0; i < n; i++)
		{
			candidate[i].index = i + 1;
			candidate[i].v = 0;
		}

		total = 0;
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < n; j++)
			{
				scanf("%lf", percentage + j);
			}

			scanf("%lld", &pop);

			total += pop;

			for (j = 0; j < n; j++)
			{
				candidate[j].v += pop * (percentage[j] + 1e-8) / 100.0;
			}
		}

		flag = 1;
		for (i = 0; i < n; i++)
		{
			if (candidate[i].v / ((double)total) >= 0.51)
			{
				printf("%d %lld\n", i + 1, candidate[i].v);
				flag = 0;
				break;
			}
		}

		if (flag)
		{
			qsort(candidate, n, sizeof(VOTE), compar);
			printf("%d %lld\n", candidate[0].index, candidate[0].v);
			printf("%d %lld\n", candidate[1].index, candidate[1].v);
		}

		if (cas < num_case - 1)
		{
			printf("\n");
		}
	}

	return 0;
}
