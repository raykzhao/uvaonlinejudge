#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

map <string, int> degree;
vector <string> alcoholName;
map <string, vector <string> > graph;

char str1[60], str2[60];

string cstrToString(char *cstr)
{
	stringstream sstr;
	sstr.str("");
	sstr << cstr;
	return sstr.str();
}

int main(int argc, char **argv)
{
	int n;
	int casNum = 0;

	while (scanf("%d", &n) == 1)
	{
		casNum++;
		getchar();

		graph.clear();
		degree.clear();
		alcoholName.clear();

		for (int i = 0; i < n; i++)
		{
			gets(str1);
			string name = cstrToString(str1);
			alcoholName.push_back(name);
			graph[name] = vector <string> ();
			degree[name] = 0;
		}

		int m;
		scanf("%d", &m);
		getchar();

		for (int i = 0; i < m; i++)
		{
			scanf("%s %s", str1, str2);
			getchar();
			
			string name1 = cstrToString(str1);
			string name2 = cstrToString(str2);

			int flag = 1;
			for (int j = 0; j < graph[name1].size(); j++)
			{
				if (!(graph[name1][j].compare(name2)))
				{
					flag = 0;
					break;
				}
			}

			if (flag)
			{
				graph[name1].push_back(name2);
				degree[name2]++;
			}
		}

		gets(str1);

		printf("Case #%d: Dilbert should drink beverages in this order:", casNum);

		for (int i = 0; i < n; i++)
		{
			for (vector <string>::iterator it = alcoholName.begin(); it != alcoholName.end(); it++)
			{
				if (!(degree[*it]))
				{
					for (int j = 0; j < graph[*it].size(); j++)
					{
						degree[graph[*it][j]]--;
					}

					degree[*it] = -1;

					printf(" %s", (*it).c_str());

					break;
				}
			}
		}

		printf(".\n\n");
	}

	return 0;
}
