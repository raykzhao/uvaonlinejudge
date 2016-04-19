#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>

using namespace std;

map <int, int> marble;
int unsorted[10010];

int compar(const void *a, const void *b)
{
	int aa = *((int *)a), bb = *((int *)b);

	return aa - bb;
}

int main(int argc, char **argv)
{
	int n, m;

	for (int cas = 1; scanf("%d %d", &n, &m) == 2; cas++)
	{
		if ((!n) && (!m))
		{
			break;
		}

		memset(unsorted, 0, sizeof(unsorted));
		marble.clear();
		for (int i = 0; i < n; i++)
		{
			scanf("%d", unsorted + i);
		}
		qsort(unsorted, n, sizeof(int), compar);

		for (int i = 0; i < n; i++)
		{
			if (marble.find(unsorted[i]) == marble.end())
			{
				marble[unsorted[i]] = i + 1;
			}
		}

		printf("CASE# %d:\n", cas);
		for (int i = 0; i < m; i++)
		{
			int x;
			scanf("%d", &x);

			if (marble.find(x) == marble.end())
			{
				printf("%d not found\n", x);
			}
			else
			{
				printf("%d found at %d\n", x, marble[x]);
			}
		}
	}

	return 0;
}
