#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <utility>
#include <string>
#include <sstream>

using namespace std;

vector < pair <string, int> > relv;

char str[110];

string cstrToString(char *str)
{
	stringstream sstr;
	sstr.str("");
	sstr << str;
	return sstr.str();
}

int main(int argc, char **argv)
{
	int numCase;

	scanf("%d", &numCase);
	getchar();

	for (int cas = 1; cas <= numCase; cas++)
	{
		int v;

		relv.clear();
		for (int i = 0; i < 10; i++)
		{
			scanf("%s %d", str, &v);
			getchar();

			string url = cstrToString(str);
			relv.push_back(make_pair(url, v));
		}

		int max = 0;
		for (int i = 0; i < relv.size(); i++)
		{
			if (relv[i].second > max)
			{
				max = relv[i].second;
			}
		}

		printf("Case #%d:\n", cas);
		for (int i = 0; i < relv.size(); i++)
		{
			if (relv[i].second == max)
			{
				puts((relv[i].first).c_str());
			}
		}
	}

	return 0;
}
