#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int num[100];

int main()
{
	int numCase;
	int cas;
	int n;
	int i;
	int j;
	int ans;

	scanf("%d", &numCase);

	for (cas = 0; cas < numCase; cas++)
	{
		scanf("%d", &n);

		for (i = 0; i < n; i++)
		{
			scanf("%d", num + i);
		}

		ans = 0;
		for (i = 0; i < n - 1; i++)
		{
			for (j = i + 1; j < n; j++)
			{
				if (num[i] > num[j])
				{
					ans++;
				}
			}
		}

		printf("Optimal train swapping takes %d swaps.\n", ans);
	}

	return 0;
}
