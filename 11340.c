#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int num_case;

double price[256];
char str[10010];

int main(int argc, char **argv)
{
	int cas;
	int chara;
	int i, j;
	char ch;
	int p;
	int line;
	double sum;

	scanf("%d", &num_case);

	for (cas = 0; cas < num_case; cas++)
	{
		scanf("%d", &chara);
		getchar();

		for (i = 0; i < 256; i++)
		{
			price[i] = 0;
		}

		for (i = 0; i < chara; i++)
		{
			scanf("%c %d", &ch, &p);
			getchar();
			
			price[ch] = ((double)p) / 100.0;
		}

		scanf("%d", &line);
		getchar();
		
		sum = 0;

		for (i = 0; i < line; i++)
		{
			gets(str);

			for (j = 0; j < strlen(str); j++)
			{
				sum += price[str[j]];
			}
		}

		printf("%.2f$\n", sum);
	}

	return 0;
}

