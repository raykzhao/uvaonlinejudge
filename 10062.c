#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct fr
{
	int ascii;
	int freq;
} FR;

char str[1010];
FR freq[130];

int compar(const void *a, const void *b)
{
	FR aa = *((FR *)a), bb = *((FR *)b);

	if (aa.freq != bb.freq)
	{
		return (aa.freq - bb.freq);
	}
	else
	{
		return (bb.ascii - aa.ascii);
	}
}

int main(int argc, char **argv)
{
	int i;
	int flag = 0;

	while (gets(str))
	{
		if (flag)
		{
			printf("\n");
		}

		for (i = 0; i < 128; i++)
		{
			freq[i].ascii = i;
			freq[i].freq = 0;
		}

		for (i = 0; i < strlen(str); (freq[str[i++]].freq)++);

		qsort(freq, 128, sizeof(FR), compar);

		for (i = 0; i < 128; i++)
		{
			if (freq[i].freq)
			{
				printf("%d %d\n", freq[i].ascii, freq[i].freq);
			}
		}
		
		flag = 1;
	}

	return 0;
}
