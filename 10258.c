#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person
{
	int no;
	int solved;
	int total_penalty;
	int penalty[20];
} PERSON;

PERSON contestant[110];

int num_case;

char str[100];

int compar(const void *a, const void *b)
{
	PERSON aa = *((PERSON *)a), bb = *((PERSON *)b);

	if ((aa.solved == -1) && (bb.solved == -1))
	{
		return 0;
	}
	if (aa.solved == -1)
	{
		return 1;
	}
	if (bb.solved == -1)
	{
		return -1;
	}

	if (aa.solved != bb.solved)
	{
		return (bb.solved - aa.solved);
	}
	else
	{
		if (aa.total_penalty != bb.total_penalty)
		{
			return (aa.total_penalty - bb.total_penalty);;
		}
		else
		{
			return (aa.no - bb.no);
		}
	}
}

int main(int argc, char **argv)
{
	int cas;
	int contestant_no, problem, time;
	char state;
	int i, j;

	scanf("%d", &num_case);
	getchar();
	gets(str);

	for (cas = 0; cas < num_case; cas++)
	{
		for (i = 0; i <= 100; i++)
		{
			contestant[i].no = i;
			contestant[i].solved = -1;
			contestant[i].total_penalty = 0;
			
			for (j = 0; j <= 9; j++)
			{
				contestant[i].penalty[j] = 0;
			}
		}

		while (gets(str))
		{
			if (!strlen(str))
			{
				break;
			}

			sscanf(str, "%d %d %d %c", &contestant_no, &problem, &time, &state);

			if (contestant[contestant_no].solved == -1)
			{
				contestant[contestant_no].solved = 0;
			}

			if (state == 'I')
			{
				contestant[contestant_no].penalty[problem] -= 20;
			}

			if (state == 'C')
			{
				if (contestant[contestant_no].penalty[problem] <= 0)
				{
					contestant[contestant_no].solved++;
					contestant[contestant_no].penalty[problem] = time - contestant[contestant_no].penalty[problem];
					contestant[contestant_no].total_penalty += contestant[contestant_no].penalty[problem];
				}
			}
		}
		
		qsort(contestant, 101, sizeof(PERSON), compar);

		for (i = 0; i <= 100 && contestant[i].solved != -1; i++)
		{
			printf("%d %d %d\n", contestant[i].no, contestant[i].solved, contestant[i].total_penalty);
		}

		if (cas < num_case - 1)
		{
			printf("\n");
		}
	}

	return 0;
}
