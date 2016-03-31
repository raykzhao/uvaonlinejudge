#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	int n, i;
	int x, y;
	int sum, dif;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &x, &y);
		sum = x + y;
		dif = x - y;

		if ((sum >= 0) && (!(sum % 2)) && (dif >= 0) && (!(dif % 2)))
		{
			printf("%d %d\n", sum / 2, dif / 2);
		}
		else
		{
			printf("impossible\n");
		}
	}

	return 0;
}
