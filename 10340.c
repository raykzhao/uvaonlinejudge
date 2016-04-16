#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str1[100000], str2[100000];

int main(int argc, char **argv)
{
	long i, j, jj;
	int flag;
	int yes_no;

	while (scanf("%s %s", str1, str2) == 2)
	{
		getchar();
		jj = 0;
		yes_no = 1;

		for (i = 0; i < strlen(str1); i++)
		{
			flag = 1;
			for (j = jj; j < strlen(str2); j++)
			{
				if (str2[j] == str1[i])
				{
					jj = j + 1;
					flag = 0;
					break;
				}
			}

			if (flag)
			{
				yes_no = 0;
				break;
			}
		}

		if (yes_no)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}

	return 0;
}
