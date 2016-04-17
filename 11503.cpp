#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sstream>
#include <map>

using namespace std;

char str[100];

typedef struct set_struct
{
	string parent;
	long size;
} setStruct;

map <string, setStruct> friendSet;

string cstrToString(char *str)
{
	stringstream sstr;
	sstr.str("");
	sstr << str;
	return sstr.str();
}

void makeSet(string x)
{
	friendSet[x].parent = x;
	friendSet[x].size = 1;
}

string findFather(string x)
{
	if (friendSet[x].parent != x)
	{
		friendSet[x].parent = findFather(friendSet[x].parent);
	}

	return friendSet[x].parent;
}

void setUnion(string x, string y)
{
	string xRoot = findFather(x), yRoot = findFather(y);

	if (!(xRoot.compare(yRoot)))
	{
		return;
	}

	if (friendSet[xRoot].size < friendSet[yRoot].size)
	{
		friendSet[xRoot].parent = yRoot;
		friendSet[yRoot].size += friendSet[xRoot].size;
	}
	else
	{
		friendSet[yRoot].parent = xRoot;
		friendSet[xRoot].size += friendSet[yRoot].size;
	}
}

int main(int argc, char **argv)
{
	int numCase;
	scanf("%d", &numCase);
	
	for (int cas = 0; cas < numCase; cas++)
	{
		long n;
		scanf("%ld", &n);
		getchar();

		friendSet.clear();
		for (long i = 0; i < n; i++)
		{
			gets(str);

			char *token = strtok(str, " ");
			string name1 = cstrToString(token);
			token = strtok(NULL, " ");
			string name2 = cstrToString(token);

			if (friendSet.find(name1) == friendSet.end())
			{
				makeSet(name1);
			}

			if (friendSet.find(name2) == friendSet.end())
			{
				makeSet(name2);
			}

			setUnion(name1, name2);

			printf("%ld\n", friendSet[findFather(name1)].size);
		}
	}

	return 0;
}
