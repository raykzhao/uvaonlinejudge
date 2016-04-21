#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>

using namespace std;

map <char, int> chara;
char str[30];
long long frac[30];

int main(int argc, char **argv)
{
	int numCase;

	frac[0] = 1;
	frac[1] = 1;
	for (int i = 2; i <= 20; i++)
	{
		frac[i] = frac[i - 1] * ((long long)i);
	}

	scanf("%d", &numCase);
	getchar();

	for (int cas = 1; cas <= numCase; cas++)
	{
		gets(str);

		chara.clear();
		for (int i = 0; i < strlen(str); i++)
		{
			if (chara.find(str[i]) == chara.end())
			{
				chara[str[i]] = 1;
			}
			else
			{
				chara[str[i]]++;
			}
		}

		printf("Data set %d: ", cas);

		long long ans = frac[strlen(str)];

		for (map <char, int>::iterator it = chara.begin(); it != chara.end(); it++)
		{
			ans /= frac[it->second];
		}

		printf("%lld\n", ans);
	}

	return 0;
}
