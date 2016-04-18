#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>

using namespace std;

map <char, char> table;
char str[50];

void initTable()
{
	table['A'] = '2';
	table['B'] = '2';
	table['C'] = '2';
	table['D'] = '3';
	table['E'] = '3';
	table['F'] = '3';
	table['G'] = '4';
	table['H'] = '4';
	table['I'] = '4';
	table['J'] = '5';
	table['K'] = '5';
	table['L'] = '5';
	table['M'] = '6';
	table['N'] = '6';
	table['O'] = '6';
	table['P'] = '7';
	table['Q'] = '7';
	table['R'] = '7';
	table['S'] = '7';
	table['T'] = '8';
	table['U'] = '8';
	table['V'] = '8';
	table['W'] = '9';
	table['X'] = '9';
	table['Y'] = '9';
	table['Z'] = '9';
	table['0'] = '0';
	table['1'] = '1';
	table['-'] = '-';
}

int main(int argc, char **argv)
{
	initTable();

	while (gets(str))
	{
		for (int i = 0; i < strlen(str); i++)
		{
			str[i] = table[str[i]];
		}

		puts(str);
	}

	return 0;
}
