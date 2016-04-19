#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	int num_case;
	int cas;
	int n, k, p;

	scanf("%d", &num_case);
	
	for (cas = 1; cas <= num_case; cas++)
	{
		scanf("%d %d %d", &n, &k, &p);

		k--;
		printf("Case %d: %d\n", cas, ((k + p) % n) + 1);
	}
	
	return 0;
}
