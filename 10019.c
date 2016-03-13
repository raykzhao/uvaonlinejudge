#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const num_one[10] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2};

int n;

int main(int argc, char **argv)
{
	int m;
	char hex[10];
	int i, j;
	int b1, b2;
	
	scanf("%d", &n);
	
	for (i = 0; i < n; i++)
	{
		b1 = 0;
		b2 = 0;
		
		scanf("%d", &m);
		
		sprintf(hex, "%d", m);
		
		while (m)
		{
			b1 += (m & 1);
			m >>= 1;
		}
		
		for (j = 0; j < strlen(hex); j++)
		{
			b2 += num_one[hex[j] - '0'];
		}
		
		printf("%d %d\n", b1, b2);
	}
	
	return 0;
}
