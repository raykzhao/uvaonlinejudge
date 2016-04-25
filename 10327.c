#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int num[1010];

int main(int argc, char **argv)
{
	int n;
	int i;
	int j;
	long ans;

	while (scanf("%d", &n) == 1)
	{
		for (i = 0; i < n; i++)
		{
			scanf("%d", num + i);
		}

		ans = 0;
		for (i = 0; i < n; i++)
		{
			for (j = i + 1; j < n; j++)
			{
				if (num[i] > num[j])
				{
					ans++;
				}
			}
		}

		printf("Minimum exchange operations : %ld\n", ans);
	}

	return 0;
}
