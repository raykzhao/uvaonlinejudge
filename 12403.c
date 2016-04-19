#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[20];
char op[20];

int main(int argc, char **argv)
{
	int num_case;
	int i;
	long x;
	long sum = 0;

	scanf("%d", &num_case);
	getchar();

	for (i = 0; i < num_case; i++)
	{
		gets(str);
		sscanf(str, "%s %ld", op, &x);

		if (!strcmp(op, "donate"))
		{
			sum += x;
		}
		else if (!strcmp(op, "report"))
		{
			printf("%ld\n", sum);
		}
	}

	return 0;
}
