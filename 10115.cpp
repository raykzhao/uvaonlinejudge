#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

char str1[500], str2[500];

vector < pair <string, string> > rule;

string cstrToString(char *str)
{
	stringstream sstr;
	sstr.str("");
	sstr << str;
	return sstr.str();
}

void do_replace(string &s)
{
	for (int i = 0; i < rule.size(); i++)
	{
		int pos;
		while ((pos = (s.find(rule[i].first))) != string::npos)
		{
			s.replace(pos, (rule[i].first).length(), rule[i].second, 0, (rule[i].second).length());
		}
	}
}

int main(int argc, char **argv)
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		if (!n)
		{
			break;
		}
		getchar();

		rule.clear();
		for (int i = 0; i < n; i++)
		{
			gets(str1);
			gets(str2);

			rule.push_back(make_pair(cstrToString(str1), cstrToString(str2)));
		}

		string ori = cstrToString(gets(str1));

		do_replace(ori);

		puts(ori.c_str());
	}

	return 0;
}
