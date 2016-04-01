#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int freq[256];

int num_case;
char str[30];

int main(int argc, char **argv)
{
	int cas;
	int r, c, m, n;
	int i, j;
	long sum;
	int max;

	scanf("%d", &num_case);

	for (cas = 1; cas <= num_case; cas++)
	{
		scanf("%d %d %d %d", &r, &c, &m, &n);
		getchar();

		for (i = 0; i < 256; i++)
		{
			freq[i] = 0;
		}

		for (i = 0; i < r; i++)
		{
			gets(str);
			
			for (j = 0; j < strlen(str); j++)
			{
				freq[str[j]]++;
			}
		}
		
		sum = 0;
		max = 0;

		for (i = 'A'; i <= 'Z'; i++)
		{
			if (freq[i] > max)
			{
				max = freq[i];
			}
		}

		for (i = 'A'; i <= 'Z'; i++)
		{
			if (freq[i] == max)
			{
				sum += (long)(freq[i]) * (long)(m);
			}
			else
			{
				sum += (long)(freq[i]) * (long)(n);
			}
		}

		printf("Case %d: %ld\n", cas, sum);
	}
	
	return 0;
}
