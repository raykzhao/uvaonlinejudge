#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sstream>
#include <map>

using namespace std;

int numCase;

map <string, long> tree;

char str[40];

int main(int argc, char **argv)
{
	scanf("%d", &numCase);
	getchar();
	gets(str);

	for (int cas = 0; cas < numCase; cas++)
	{
		tree.clear();

		long count = 0;

		while (gets(str))
		{
			if (!strlen(str))
			{
				break;
			}

			stringstream sstr;
			sstr.str("");
			sstr << str;
			string name = sstr.str();

			(tree[name])++;
			count++;
		}

		map <string, long>::iterator it;

		for (it = tree.begin(); it != tree.end(); it++)
		{
			printf("%s %.4f\n", (*it).first.c_str(), (double)((*it).second) / ((double)count) * (double)(100.0));
		}

		if (cas < numCase - 1)
		{
			printf("\n");
		}
	}

	return 0;
}
