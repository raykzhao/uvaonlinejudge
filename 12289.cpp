#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <string>
#include <sstream>

using namespace std;

map <string, int> all;

char str[10];

string cstrToString(char *str)
{
	stringstream sstr;
	sstr.str("");
	sstr << str;
	return sstr.str();
}

int genAll()
{
	char str[10];
	for (char i = 'a'; i <= 'z'; i++)
	{
		sprintf(str, "%cne", i);
		all[cstrToString(str)] = 1;
		sprintf(str, "o%ce", i);
		all[cstrToString(str)] = 1;
		sprintf(str, "on%c", i);
		all[cstrToString(str)] = 1;
		sprintf(str, "%cwo", i);
		all[cstrToString(str)] = 2;
		sprintf(str, "t%co", i);
		all[cstrToString(str)] = 2;
		sprintf(str, "tw%c", i);
		all[cstrToString(str)] = 2;
		sprintf(str, "%chree", i);
		all[cstrToString(str)] = 3;
		sprintf(str, "t%cree", i);
		all[cstrToString(str)] = 3;
		sprintf(str, "th%cee", i);
		all[cstrToString(str)] = 3;
		sprintf(str, "thr%ce", i);
		all[cstrToString(str)] = 3;
		sprintf(str, "thre%c", i);
		all[cstrToString(str)] = 3;
	}
}

int main(int argc, char **argv)
{
	genAll();

	int numCase;
	scanf("%d", &numCase);
	getchar();

	for (int cas = 0; cas < numCase; cas++)
	{
		gets(str);
		string w = cstrToString(str);

		printf("%d\n", all[w]);
	}
	return 0;
}
