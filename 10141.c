#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[100];

typedef struct proposal
{
	char name[100];
	double price;
	int num;
	int order;
} PROPOSAL;

PROPOSAL data[10000];

int compar(const void *a, const void *b)
{
	PROPOSAL aa = *((PROPOSAL *)a), bb = *((PROPOSAL *)b);

	if (aa.num > bb.num)
	{
		return -1;
	}
	else if (aa.num < bb.num)
	{
		return 1;
	}
	else
	{
		if (aa.price < bb.price)
		{
			return -1;
		}
		else if (aa.price > bb.price)
		{
			return 1;
		}
		else
		{
			if (aa.order < bb.order)
			{
				return -1;
			}
			else if (aa.order > bb.order)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
}

int main()
{
	int cas;
	int n, p;
	int i, j;

	for (cas = 1; ; cas++)
	{
		scanf("%d %d", &n, &p);
		getchar();

		if (!n && !p)
		{
			break;
		}

		if (cas > 1)
		{
			printf("\n");
		}

		for (i = 0; i < n; i++)
		{
			gets(str);
		}

		for (i = 0; i < p; i++)
		{
			data[i].order = i;
			gets(data[i].name);
			scanf("%lf %d", &data[i].price, &data[i].num);
			getchar();

			for (j = 0; j < data[i].num; j++)
			{
				gets(str);
			}
		}

		qsort(data, p, sizeof(PROPOSAL), compar);

		printf("RFP #%d\n", cas);
		puts(data[0].name);
	}

	return 0;
}
