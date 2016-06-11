#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <list>

using namespace std;

char str[100010];

list <char> output;

int main(int argc, char **argv)
{
	while (gets(str))
	{
		output.clear();
		list <char>::iterator it = output.begin();
		int len = strlen(str);

		for (int i = 0; i < len; i++)
		{
			if (str[i] == '[')
			{
				it = output.begin();
			}
			else if (str[i] == ']')
			{
				it = output.end();
			}
			else
			{
				output.insert(it, str[i]);
			}
		}

		for (it = output.begin(); it != output.end(); it++)
		{
			putchar(*it);
		}
		printf("\n");
	}

	return 0;
}
