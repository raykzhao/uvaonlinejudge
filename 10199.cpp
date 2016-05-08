#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sstream>
#include <map>
#include <set>

using namespace std;

map <string, set <string> > graph;

map <string, int> visited;
map <string, int> depth;
map <string, int> low;
map <string, string> parent;

set <string> output;

char str1[50], str2[50];

string cstrToString(char *str)
{
	stringstream sstr;
	sstr.str("");
	sstr << str;
	return sstr.str();
}

int min_int(int a, int b)
{
	return (a < b) ? a : b;
}

void do_dfs(string x, int d)
{
	visited[x] = 1;
	depth[x] = d;
	low[x] = d;

	int count = 0;
	int cut = 0;

	for (set <string>::iterator it = graph[x].begin(); it != graph[x].end(); it++)
	{
		if (!visited[*it])
		{
			parent[*it] = x;
			do_dfs(*it, d + 1);
			count++;

			if (low[*it] >= depth[x])
			{
				cut = 1;
			}

			low[x] = min_int(low[x], low[*it]);
		}
		else if (*it != parent[x])
		{
			low[x] = min_int(low[x], depth[*it]);
		}
	}

	if (((parent[x] != "") && (cut)) || ((parent[x] == "") && (count > 1)))
	{
		output.insert(x);
	}
}

int main(int argc, char **argv)
{
	int n;
	for (int cas = 1; scanf("%d", &n) == 1; cas++)
	{
		if (!n)
		{
			break;
		}

		getchar();

		graph.clear();
		visited.clear();
		depth.clear();
		low.clear();
		parent.clear();
		output.clear();

		for (int i = 0; i < n; i++)
		{
			gets(str1);

			string name = cstrToString(str1);

			graph[name] = set <string> ();
			visited[name] = 0;
			depth[name] = 0;
			low[name] = 0;
			parent[name] = "";
		}

		int m;
		scanf("%d", &m);
		getchar();

		for (int i = 0; i < m; i++)
		{
			scanf("%s %s", str1, str2);
			getchar();

			string u = cstrToString(str1);
			string v = cstrToString(str2);

			graph[u].insert(v);
			graph[v].insert(u);
		}

		for (map <string, set <string> >::iterator it = graph.begin(); it != graph.end(); it++)
		{
			if (!visited[it->first])
			{
				do_dfs(it->first, 0);
			}
		}

		if (cas != 1)
		{
			printf("\n");
		}

		printf("City map #%d: %ld camera(s) found\n", cas, output.size());

		for (set <string>::iterator it = output.begin(); it != output.end(); it++)
		{
			puts((*it).c_str());
		}
	}

	return 0;
}
