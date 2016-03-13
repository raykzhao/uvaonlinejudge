#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	unsigned long long int x, y;
	unsigned long long int curx, cury;
	unsigned long long int count;
	unsigned long long int flag;
	
	scanf("%llu %llu", &x, &y);
	
	while ((x != 0) || (y != 0))
	{
		count = 0;
		if (x < y)
		{
			curx = x; x = y; y = curx;
		}
		
		flag = 0;
		while (x)
		{
			curx = x % 10;
			cury = y % 10;
			if (curx + cury + flag >= 10)
			{
				count++;
				flag = 1;
			}
			else
			{
				flag = 0;
			}
			x /= 10;
			y /= 10;
		}
		
		if (count == 0)
		{
			printf("No carry operation.\n");
		}
		else if (count == 1)
		{
			printf("1 carry operation.\n");
		}
		else
		{
			printf("%llu carry operations.\n", count);
		}
		scanf("%llu %llu", &x, &y);
	}
	
	return 0;
}
