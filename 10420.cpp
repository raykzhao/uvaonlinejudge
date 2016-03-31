#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sstream>
#include <set>

using namespace std;

multiset <string> countryCount;

int numLine;

int main (int argc, char **argv)
{
	int line;

	scanf("%d", &numLine);
	getchar();

	for (line = 0; line < numLine; line++)
	{
		char str[100];
		gets(str);
		char *nameStr = strchr(str, ' ');
		*nameStr = 0;

		stringstream sstr;
		sstr.str("");
		sstr << str;
		string country = sstr.str();

		countryCount.insert(country);
	}

	multiset <string>::iterator setIt = countryCount.begin();

	while (setIt != countryCount.end())
	{
		string country = *setIt;
		printf("%s %d\n", country.c_str(), countryCount.count(country));

		setIt = (countryCount.equal_range(country)).second;
	}

	return 0;
}
