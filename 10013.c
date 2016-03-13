#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int num_case;

long int m;

int res[1000010];

int main(int argc, char **argv)
{
	int cas, x, y;
	long int i;
	int carry;
	
	scanf("%d", &num_case);
	
	for (cas = 0; cas < num_case; cas++)
	{
		scanf("%ld", &m);

		for (i = 0; i < m; i++)
		{
			scanf("%d %d", &x, &y);
			getchar();
			res[i] = x + y;
		}
		
		carry = 0;
		for (i = m - 1; i >= 0; i--)
		{
			res[i] += carry;
			
			if (res[i] >= 10)
			{
				res[i] -= 10;
				carry = 1;
			}
			else
			{
				carry = 0;
			}
		}
		
		if (carry)
		{
			printf("%d", carry);
		}
		
		for (i = 0; i < m; i++)
		{
			printf("%d", res[i]);
		}
		
		printf("\n");
		
		if (cas < num_case - 1)
		{
			printf("\n");
		}
	}
	
	return 0;
}
