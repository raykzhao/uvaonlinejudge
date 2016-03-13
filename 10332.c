#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[15];
int main(int argc, char **argv)
{
	int i;
	int sum;
	
	while (1)
	{
		scanf("%s", str);
		if (str[0] == '0')
			break;
		
		sum = 10;
		while (sum >= 10)
		{
			for (sum = 0, i = 0; i < strlen(str); i++)
			{
				sum += str[i] - 48;
			}
			sprintf(str, "%d", sum);
		}
		
		printf("%d\n", sum);
	}
	return 0;
}
