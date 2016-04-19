#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <set>

using namespace std;

char numToChar[10][10] = {{},
						{'B', 'F', 'P', 'V'},
						{'C', 'G', 'J', 'K', 'Q', 'S', 'X', 'Z'},
						{'D', 'T'},
						{'L'},
						{'M', 'N'},
						{'R'}
};

char charToNum[30];

char str[50];
char output[50];

set <char> represent;

void genCharToNum()
{
	for (int i = 1; i <= 6; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (numToChar[i][j])
			{
				charToNum[numToChar[i][j] - 'A'] = i;
			}
		}
	}
}

int main(int argc, char **argv)
{
	genCharToNum();

	while (gets(str))
	{
		memset(output, 0, sizeof(output));

		int c = 0;
		represent.clear();
		for (int i = 0; i < strlen(str); i++)
		{
			if (charToNum[str[i] - 'A'])
			{
				if (represent.find(str[i]) == represent.end())
				{
					represent.clear();
					
					output[c++] = charToNum[str[i] - 'A'] + '0';

					for (int j = 0; j < 8; j++)
					{
						if (numToChar[charToNum[str[i] - 'A']][j])
						{
							represent.insert(numToChar[charToNum[str[i] - 'A']][j]);
						}
					}
				}
			}
			else
			{
				represent.clear();
			}
		}

		puts(output);
	}

	return 0;
}
