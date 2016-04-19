#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[10];

int main(int argc, char **argv)
{
	int cas;
	for (cas = 1; gets(str); cas++)
	{
		if (!strcmp(str, "*"))
		{
			break;
		}

		printf("Case %d: ", cas);

		if (!strcmp(str, "Hajj"))
		{
			printf("Hajj-e-Akbar\n");
		}
		else if (!strcmp(str, "Umrah"))
		{
			printf("Hajj-e-Asghar\n");
		}
	}

	return 0;
}
