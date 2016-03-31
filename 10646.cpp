#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int numCase;
char str[10];

vector <string> pile;

int main(int argc, char **argv)
{
	scanf("%d", &numCase);

	for (int cas = 1; cas <= numCase; cas++)
	{
		pile.clear();

		for (int i = 0; i < 52; i++)
		{
			scanf("%s", str);
			
			stringstream sstr;
			sstr.str("");
			sstr << str;
			string name = sstr.str();

			pile.insert(pile.begin(), name);
		}

		int y = 0;

		for (int i = 0; i < 3; i++)
		{
			int x = pile[25][0];
			
			if ((x >= '2') && (x <= '9'))
			{
				x -= '0';
			}
			else
			{
				x = 10;
			}
			y += x;
			pile.erase(pile.begin() + 25, pile.begin() + 36 - x);
		}

		printf("Case %d: %s\n", cas, pile[pile.size() - y].c_str());
	}

	return 0;
}
