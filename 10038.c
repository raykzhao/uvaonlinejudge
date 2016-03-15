#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int squence[3010];
int check[3010];

int main(int argc, char **argv)
{
	int n;
	int i;
	int flag;

	while (scanf("%d", &n) == 1)
	{
		for (i = 0; i < n; i++)
		{
			scanf("%d", squence + i);
		}

		for (i = 1; i <= n - 1; i++)
		{
			check[i] = 0;
		}

		for (i = 0; i < n - 1; i++)
		{
			check[abs(squence[i] - squence[i + 1])] = 1;
		}

		flag = 0;
		for (i = 1; i <= n - 1; i++)
		{
			if (!check[i])
			{
				flag = 1;
				break;
			}
		}

		if (flag)
		{
			printf("Not jolly\n");
		}
		else
		{
			printf("Jolly\n");
		}
	}
	return 0;
}
