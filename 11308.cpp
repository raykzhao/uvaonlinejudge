#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <map>
#include <sstream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int numCase;

map <string, int> ingredient;
vector <pair <string, long> > recipeList;

char str[200];

string cstrToString(char *cstr)
{
	stringstream sstr;
	sstr.str("");
	sstr << cstr;
	return (sstr.str());
}

bool compar(pair <string, long> i, pair <string, long> j)
{
	if (i.second != j.second)
	{
		if (i.second - j.second < 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if ((i.first).compare(j.first) < 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

int main(int argc, char **argv)
{
	scanf("%d", &numCase);
	getchar();

	for (int cas = 0; cas < numCase; cas++)
	{
		gets(str);

		for (int i = 0; i < strlen(str); i++)
		{
			if ((str[i] >= 'a') && (str[i] <='z'))
			{
				str[i] -= 32;
			}
		}

		string binder = cstrToString(str);

		int m, n;
		long budget;

		scanf("%d %d %ld", &m, &n, &budget);
		getchar();
		
		ingredient.clear();

		for (int i = 0; i < m; i++)
		{
			int price;

			scanf("%s %d", str, &price);
			getchar();

			ingredient[cstrToString(str)] = price;
		}

		printf("%s\n", binder.c_str());

		recipeList.clear();

		for (int i = 0; i < n; i++)
		{
			gets(str);
			string recipe = cstrToString(str);

			int k;
			scanf("%d", &k);
			getchar();

			long sum = 0;
			for (int j = 0; j < k; j++)
			{
				int count;
				scanf("%s %d", str, &count);
				getchar();

				sum += ((long)count) * ((long)(ingredient[cstrToString(str)]));
			}
			
			if (sum <= budget)
			{
				recipeList.push_back(make_pair(recipe, sum));
			}
		}

		if (!recipeList.size())
		{
			printf("Too expensive!\n");
		}
		else
		{
			sort(recipeList.begin(), recipeList.end(), compar);
		
			for (int i = 0; i < recipeList.size(); i++)
			{
				printf("%s\n", (recipeList[i].first).c_str());
			}
		}

		printf("\n");
	}

	return 0;
}
