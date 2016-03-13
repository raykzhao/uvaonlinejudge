#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[105];

int main(int argc, char **argv)
{
	int t;
	int i, j;
	int sum;
	
	scanf("%d", &t);
	getchar();
	
	for (i = 0; i < t; i++)
	{
		sum = 0;
		gets(str);
		for (j = 0; j < strlen(str); j++)
		{
			switch (str[j])
			{
				case 'a':
				case 'd':
				case 'g':
				case 'j':
				case 'm':
				case 'p':
				case 't':
				case 'w':
				case ' ':
					sum++;
					break;
				case 'b':
				case 'e':
				case 'h':
				case 'k':
				case 'n':
				case 'q':
				case 'u':
				case 'x':
					sum += 2;
					break;
				case 'c':
				case 'f':
				case 'i':
				case 'l':
				case 'o':
				case 'r':
				case 'v':
				case 'y':
					sum += 3;
					break;
				case 's':
				case 'z':
					sum += 4;
					break;
			}
		}
		
		printf("Case #%d: %d\n", i + 1, sum);
	}
	return 0;
}
