#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str1[10000], str2[10000];
char str_i1[10000], str_i2[10000];

int main(int argc, char **argv)
{
	char *token;
	int c1, c2;

	while (gets(str1))
	{
		gets(str2);

		c1 = 0;
		memset(str_i1, 0, sizeof(str_i1));
		token = strtok(str1, " ");
		while (token != NULL)
		{
			if (token[0] != ' ')
			{
				str_i1[c1++] = token[0];
			}
			token = strtok(NULL, " ");
		}

		c2 = 0;
		memset(str_i2, 0, sizeof(str_i2));
		token = strtok(str2, " ");
		while (token != NULL)
		{
			if (token[0] != ' ')
			{
				str_i2[c2++] = token[0];
			}
			token = strtok(NULL, " ");
		}

		if (!strcmp(str_i1, str_i2))
		{
			puts("yes");
		}
		else
		{
			puts("no");
		}
	}
	return 0;
}
