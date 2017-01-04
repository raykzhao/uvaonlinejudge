#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[5000];

int main(int argc, char **argv)
{
	int i;
	while (gets(str))
	{
		for (i = 0; i < strlen(str); i++)
		{
			str[i] -= 7;
		}

		puts(str);
	}

	return 0;
}
