#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

int num_case;
char str[20];

int compar(const void *a, const void *b)
{
	char aa = *((char *)a), bb = *((char *)b);

	return ((int)aa - (int)bb);
}

int main(int argc, char **argv)
{
	int cas;

	scanf("%d", &num_case);

	for (cas = 0; cas < num_case; cas++)
	{
		scanf("%s", str);
		
		qsort(str, strlen(str), sizeof(char), compar);

		do
		{
			printf("%s\n", str);
		} while (next_permutation(str, str + strlen(str)));

		printf("\n");
	}
	return 0;
}
