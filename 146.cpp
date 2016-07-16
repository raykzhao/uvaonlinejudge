#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

char str[100];

int main()
{
	while (gets(str))
	{
		if (str[0] == '#' && strlen(str) == 1)
		{
			break;
		}

		if (std::next_permutation(str, str + strlen(str)))
		{
			puts(str);
		}
		else
		{
			puts("No Successor");
		}
	}

	return 0;
}
