#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <deque>
#include <set>
#include <sstream>
#include <string>

using namespace std;

map <string, set <string> > graph;
map <string, set <string> > reverseGraph;
map <string, string> scc;
set <string> sccRoot;
deque <string> q;
set <string> visited;

int n;
char str1[50], str2[50];

string cstrToString(char *cstr)
{
	stringstream sstr;
	sstr.str("");
	sstr << cstr;
	return sstr.str();
}

void do_scc_visit(string name)
{
	if (visited.find(name) == visited.end())
	{
		visited.insert(name);
		
		for (set <string>::iterator it = graph[name].begin(); it != graph[name].end(); it++)
		{
			do_scc_visit(*it);
		}
		
		q.push_front(name);
	}
}

void do_scc_assign(string name, string root)
{
	if (scc.find(name) == scc.end())
	{
		scc[name] = root;

		for (set <string>::iterator it = reverseGraph[name].begin(); it != reverseGraph[name].end(); it++)
		{
			do_scc_assign(*it, root);
		}
	}
}

void do_scc()
{
	scc.clear();
	sccRoot.clear();
	q = deque <string> ();
	visited.clear();

	for (map <string, set <string> >::iterator it = graph.begin(); it != graph.end(); it++)
	{
		do_scc_visit(it->first);
	}

	while (!q.empty())
	{
		string name = q.front();
		do_scc_assign(name, name);
		q.pop_front();
	}

	for (map <string, string>::iterator it = scc.begin(); it != scc.end(); it++)
	{
		sccRoot.insert(it->second);
	}

	printf("%d\n", sccRoot.size());
}

int main(int argc, char **argv)
{
	long m;

	while (scanf("%d %ld", &n, &m) == 2)
	{
		if ((!n) && (!m))
		{
			break;
		}

		graph.clear();
		reverseGraph.clear();
		getchar();
		for (int i = 0; i < n; i++)
		{
			gets(str1);
			string name = cstrToString(str1);
			
			graph[name] = set <string> ();
			reverseGraph[name] = set <string> ();
		}

		for (long i = 0; i < m; i++)
		{
			gets(str1);
			string name1 = cstrToString(str1);
			gets(str2);
			string name2 = cstrToString(str2);

			if ((graph.find(name1) != graph.end()) && (graph.find(name2) != graph.end()))
			{
				graph[name1].insert(name2);
				reverseGraph[name2].insert(name1);
			}
		}

		do_scc();
	}

	return 0;
}
