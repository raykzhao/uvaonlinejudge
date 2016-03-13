#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int n[1000000];

int main(int argc, char **argv)
{
	unsigned int i, j;
	unsigned int io, jo;
	unsigned int k;
	unsigned int max;
	unsigned int cur;
	
	while (scanf("%u %u\n",&i,&j)==2)
	{
		max = 0;
		io = i; jo = j;
		if (i > j)
		{
			k = i; i = j; j = k;
		}
		
		for (k = i; k <= j; k++)
		{
			if (!n[k])
			{
				n[k] = 1;
				cur = k;
				while (cur != 1)
				{
					if (cur % 2)
					{
						cur = cur * 3 + 1;
					}
					else
					{
						cur /= 2;
					}
					n[k]++;
				}
			}
			
			if (n[k] > max)
			{
				max = n[k];
			}
		}
		
		printf("%u %u %u\n", io, jo, max);
	}
	
	return 0;
}
