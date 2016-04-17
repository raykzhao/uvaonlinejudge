#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <set>

using namespace std;

char str[1010][10000];
int num[1010];
set <int> neighbour;

int main(int argc, char **argv)
{
	int num_case;
	int cas;
	int n;
	int i, j;
	char *token;
	int x;

	scanf("%d", &num_case);

	for (cas = 0; cas < num_case; cas++)
	{
		scanf("%d", &n);
		getchar();

		for (i = 0; i < n; i++)
		{
			gets(str[i]);

			for (j = strlen(str[i]) - 1; j >= 0 && str[i][j] == ' '; str[i][j--] = 0);

			neighbour.clear();
			token = strtok(str[i], " ");
			while (token != NULL)
			{
				x = atoi(token);
				neighbour.insert(x);
				token = strtok(NULL, " ");
			}

			num[i] = neighbour.size();
		}

		int min = 40;
		for (i = 0; i < n; i++)
		{
			if (num[i] < min)
			{
				min = num[i];
			}
		}

		for (i = 0; i < n && num[i] > min; i++);
		printf("%d", ++i);
		for (; i < n; i++)
		{
			if (num[i] == min)
			{
				printf(" %d", i + 1);
			}
		}
		printf("\n");
	}

	return 0;
}
