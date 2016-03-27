#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sstream>
#include <utility>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int numCase;

string st;
vector <pair <string, string> > rule;
set <string> gen;

int count;

string cstrToString(char *str)
{
	stringstream strStream;
	
	strStream.str("");
	strStream << str;
	return (strStream.str());
}

void doClosure()
{
	if (count > 1000)
	{
		return;
	}

	gen.clear();
	gen.insert(st);
	queue <string> strQueue;
	strQueue.push(st);

	while (!strQueue.empty())
	{
		string cur = strQueue.front();
		strQueue.pop();
		
		for (int i = 0; i < rule.size(); i++)
		{
			int pos = -1;

			while ((pos = cur.find(rule[i].first, pos + 1)) != cur.npos)
			{
				string newGen = cur;
				
				newGen.replace(pos, rule[i].first.length(), rule[i].second);
				
				if (gen.find(newGen) == gen.end())
				{
					if ((++count) > 1000)
					{
						return;
					}

					gen.insert(newGen);
					strQueue.push(newGen);
				}
			}
		}
	}
}

int main(int argc, char **argv)
{
	char sLine[50];

	scanf("%d", &numCase);
	getchar();
	gets(sLine);

	for (int cas = 0; cas < numCase; cas++)
	{
		scanf("\"%[A-Z|a-z|\"]", sLine);
		getchar();

		sLine[strlen(sLine) - 1] = 0;
		st = cstrToString(sLine);

		rule.clear();

		count = 1;

		while (gets(sLine))
		{
			if (!strlen(sLine))
			{
				break;
			}

			char cStr1[15], cStr2[15];
			sscanf(sLine, "\"%[A-Z|a-z|\"]->\"%[A-Z|a-z|\"]", cStr1, cStr2);
			
			cStr1[strlen(cStr1) - 1] = 0;
			cStr2[strlen(cStr2) - 1] = 0;
			string str1 = cstrToString(cStr1);
			string str2 = cstrToString(cStr2);

			if ((!str1.length()) && (str2.length()))
			{
				count = 1001;
			}

			if ((str1.compare(str2) != 0) && (str2.find(str1) != str2.npos))
			{
				count = 1001;
			}

			rule.push_back(make_pair(str1, str2));
		}
		
		doClosure();

		if (count > 1000)
		{
			printf("Too many.\n");
		}
		else
		{
			printf("%d\n", count);
		}

		if (cas < numCase - 1)
		{
			printf("\n");
		}
	}

	return 0;
}
