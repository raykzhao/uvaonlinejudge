#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <string>
#include <sstream>
#include <queue>
#include <utility>

using namespace std;

map <string, map <string, map <char, int> > > graph;
map <string, map <char, long> > dist;

queue < pair <string, char> > q;

char str1[60], str2[60], str3[60];

string cstrToString(char *cstr)
{
	stringstream sstr;
	sstr.str("");
	sstr << cstr;
	return sstr.str();
}

void doSPFA(string start)
{
	q.push(make_pair(start, 0));
	dist[start][0] = 0;

	while (!q.empty())
	{
		pair <string, char> cur = q.front();
		q.pop();

		for (map <string, map <char, int> >::iterator vIt = graph[cur.first].begin(); vIt != graph[cur.first].end(); vIt++)
		{
			for (map <char, int>::iterator eIt = graph[cur.first][vIt->first].begin(); eIt != graph[cur.first][vIt->first].end(); eIt++)
			{
				if (eIt->first != cur.second)
				{
					if (dist[cur.first][cur.second] + (long)(eIt->second) < dist[vIt->first][eIt->first])
					{
						dist[vIt->first][eIt->first] = dist[cur.first][cur.second] + (long)(eIt->second);

						q.push(make_pair(vIt->first, eIt->first));
					}
				}
			}
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

		graph.clear();
		dist.clear();

		scanf("%s %s", str1, str2);
		getchar();

		string startName = cstrToString(str1);
		string endName = cstrToString(str2);

		graph[startName] = map <string, map <char, int> > ();
		graph[endName] = map <string, map <char, int> > ();

		dist[startName] = map <char, long> ();
		dist[endName] = map <char, long> ();

		for (int i = 0; i < n; i++)
		{
			scanf("%s %s %s", str1, str2, str3);
			getchar();

			string lang1 = cstrToString(str1);
			string lang2 = cstrToString(str2);
			string word = cstrToString(str3);

			if (graph.find(lang1) == graph.end())
			{
				graph[lang1] = map <string, map <char, int> > ();
			}

			if (graph.find(lang2) == graph.end())
			{
				graph[lang2] = map <string, map <char, int> > ();
			}

			if (graph[lang1].find(lang2) == graph[lang1].end())
			{
				graph[lang1][lang2] = map <char, int> ();
			}

			if (graph[lang2].find(lang1) == graph[lang2].end())
			{
				graph[lang2][lang1] = map <char, int> ();
			}

			if (graph[lang1][lang2].find(word[0]) == graph[lang1][lang2].end())
			{
				graph[lang1][lang2][word[0]] = word.length();
			}
			else
			{
				if (word.length() < graph[lang1][lang2][word[0]])
				{
					graph[lang1][lang2][word[0]] = word.length();
				}
			}

			if (graph[lang2][lang1].find(word[0]) == graph[lang2][lang1].end())
			{
				graph[lang2][lang1][word[0]] = word.length();
			}
			else
			{
				if (word.length() < graph[lang2][lang1][word[0]])
				{
					graph[lang2][lang1][word[0]] = word.length();
				}
			}

			if (dist.find(lang1) == dist.end())
			{
				dist[lang1] = map <char, long> ();
			}

			if (dist.find(lang2) == dist.end())
			{
				dist[lang2] = map <char, long> ();
			}
		}

		for (map <string, map <char, long> >::iterator it = dist.begin(); it != dist.end(); it++)
		{
			for (char ch = 'a'; ch <= 'z'; ch++)
			{
				(it->second)[ch] = 200000;
			}
		}

		doSPFA(startName);

		long min = 200000;

		for (map <char, long>::iterator it = dist[endName].begin(); it != dist[endName].end(); it++)
		{
			if (it->second < min)
			{
				min = it->second;
			}
		}

		if (min == 200000)
		{
			printf("impossivel\n");
		}
		else
		{
			printf("%ld\n", min);
		}
	}

	return 0;
}
