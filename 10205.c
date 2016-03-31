#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char name_of_value[13][10] = {"2", "3", "4", "5", "6", "7", "8", "9", "10","Jack", "Queen", "King", "Ace"};

const char name_of_suit[4][10] = {"Clubs", "Diamonds", "Hearts", "Spades"};

char name_of_card[55][25];

int num_case;

char str[10];

int rule[110][55];

void init_name_of_card()
{
	int i, j;
	
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 13; j++)
		{
			sprintf(name_of_card[i * 13 + j + 1], "%s of %s", name_of_value[j], name_of_suit[i]);
		}
	}
}

int main(int argc, char **argv)
{
	int cas;
	int n;
	int i, j;
	int *old, *new;
	int x;

	init_name_of_card();

	scanf("%d", &num_case);
	getchar();
	gets(str);

	for (cas = 0; cas < num_case; cas++)
	{
		scanf("%d", &n);
		
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= 52; j++)
			{
				scanf("%d", &(rule[i][j]));
			}
		}

		getchar();
		
		old = (int *)malloc(55 * sizeof(int));

		for (i = 1; i <= 52; i++)
		{
			old[i] = i;
		}

		while (gets(str))
		{
			if (!strlen(str))
			{
				break;
			}

			new = (int *)malloc(55 * sizeof(int));
			x = atoi(str);
			for (i = 1; i <= 52; i++)
			{
				new[i] = old[rule[x][i]];
			}

			free(old);
			old = new;
		}

		for (i = 1; i <= 52; i++)
		{
			printf("%s\n", name_of_card[old[i]]);
		}

		if (cas < num_case - 1)
		{
			printf("\n");
		}

		free(old);
	}

	return 0;
}
