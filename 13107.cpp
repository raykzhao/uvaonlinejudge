#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>

using namespace std;

map <char, int> match;

char str[1000000];
int curMatch;
char output[1000000];
int pos;

int main(int argc, char **argv)
{
	while (gets(str))
	{
		match.clear();
		curMatch = 1;
		pos = 0;

		for (long i = 0; i < strlen(str); i++)
		{
			if (match.find(str[i]) == match.end())
			{
				match[str[i]] = curMatch++;

				switch (match[str[i]])
				{
					case 2:
						match[str[i]] = 5;
						break;
					case 5:
						match[str[i]] = 2;
						break;
					case 6:
						match[str[i]] = 9;
						break;
					case 9:
						match[str[i]] = 6;
						break;
					case 12:
						match[str[i]] = 15;
						break;
					case 15:
						match[str[i]] = 12;
						break;
					case 16:
						match[str[i]] = 19;
						break;
					case 19:
						match[str[i]] = 16;
						break;
					case 20:
						match[str[i]] = 50;
						break;
					case 21:
						match[str[i]] = 51;
						break;
					case 22:
						match[str[i]] = 55;
						break;
					case 23:
						match[str[i]] = 53;
						break;
					case 24:
						match[str[i]] = 54;
						break;
					case 25:
						match[str[i]] = 52;
						break;
					case 26:
						match[str[i]] = 59;
						break;
				}
			}

			if (match[str[i]] < 10)
			{
				output[pos++] = match[str[i]] + '0';
			}
			else
			{
				output[pos++] = (match[str[i]] / 10) + '0';
				output[pos++] = (match[str[i]] % 10) + '0';
			}
		}

		output[pos] = 0;

		puts(output);
	}

	return 0;
}
