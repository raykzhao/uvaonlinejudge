#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct task_ts
{
	int num, t, s;
} TASK_TS;

int num_case;
int n;
TASK_TS task[1010];

int compar(const void *a, const void *b)
{
	TASK_TS aa = *((TASK_TS *)a), bb = *((TASK_TS *)b);
	
	double p1 = (double)(aa.s) / (double)(aa.t);
	double p2 = (double)(bb.s) / (double)(bb.t);

	if (p1 < p2)
	{
		return 1;
	}
	else if (p1 > p2)
	{
		return -1;
	}
	else
	{
		return (aa.num - bb.num);
	}
}

int main(int argc, char **argv)
{
	int cas;
	int i;

	scanf("%d", &num_case);

	for (cas = 0; cas < num_case; cas++)
	{
		scanf("%d", &n);

		for (i = 0; i < n; i++)
		{
			scanf("%d %d", &(task[i].t), &(task[i].s));

			task[i].num = i + 1;
		}

		qsort(task, n, sizeof(TASK_TS), compar);

		for (i = 0; i < n; i++)
		{
			printf("%d", task[i].num);

			if (i < (n - 1))
			{
				printf(" ");
			}
		}

		printf("\n");

		if (cas < (num_case - 1))
		{
			printf("\n");
		}
	}

	return 0;
}
