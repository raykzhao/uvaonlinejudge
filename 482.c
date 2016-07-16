#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[1000][1000];

char str_in[100000];
int order[1000];

int main()
{
	int numCase;
	int cas;
	char *token;
	int count;
	int i;

	scanf("%d", &numCase);
	getchar();
	for (cas = 0; cas < numCase; cas++)
	{
		gets(str_in);

		count = 0;
		gets(str_in);
		token = strtok(str_in, " ");
		while (token != NULL)
		{
			order[count++] = atoi(token) - 1;
			token = strtok(NULL, " ");
		}

		count = 0;
		gets(str_in);
		token = strtok(str_in, " ");
		while (token != NULL)
		{
			strcpy(str[order[count++]], token);
			token = strtok(NULL, " ");
		}

		for (i = 0; i < count; i++)
		{
			puts(str[i]);
		}

		if (cas < numCase - 1)
		{
			printf("\n");
		}
	}

	return 0;
}
