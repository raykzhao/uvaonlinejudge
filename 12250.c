#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[20];
const char lang[6][2][20] = {{"HELLO", "ENGLISH"},
							{"HOLA", "SPANISH"},
							{"HALLO", "GERMAN"},
							{"BONJOUR", "FRENCH"},
							{"CIAO", "ITALIAN"},
							{"ZDRAVSTVUJTE", "RUSSIAN"}};

int main(int argc, char **argv)
{
	int cas;
	int i;
	int flag;

	for (cas = 1; gets(str); cas++)
	{
		if (!strcmp(str, "#"))
		{
			break;
		}

		flag = 1;
		printf("Case %d: ", cas);
		for (i = 0; i < 6; i++)
		{
			if (!strcmp(str, lang[i][0]))
			{
				puts(lang[i][1]);
				flag = 0;
				break;
			}
		}

		if (flag)
		{
			puts("UNKNOWN");
		}
	}

	return 0;
}
