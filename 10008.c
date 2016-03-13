#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct xy
{
	char chara;
	int count;
} XY;

char str[200];

XY count[26];

int n;

int compar(const void *a, const void *b)
{
	XY aa = *((XY *)a);
	XY bb = *((XY *)b);
	
	if (aa.count != bb.count)
	{
		return (bb.count - aa.count);
	}
	else
	{
		return (aa.chara - bb.chara);
	}
}

int main(int argc, char **argv)
{
	int i;
	int j;
	
	for (i = 0; i < 26; i++)
	{
		count[i].chara = i + 'A';
	}
	
	scanf("%d", &n);
	
	getchar();
	
	for (i = 0; i < n; i++)
	{
		gets(str);
		
		for (j = 0; j < strlen(str); j++)
		{
			if ((str[j] >= 'A') && (str[j] <= 'Z'))
			{
				count[str[j] - 'A'].count++;
			}
			else if ((str[j] >= 'a') && (str[j] <= 'z'))
			{
				count[str[j] - 'a'].count++;
			}
		}
	}
	
	qsort(count, 26, sizeof(XY), compar);
	
	for (i = 0; i < 26; i++)
	{
		if (count[i].count)
		{
			printf("%c %d\n", count[i].chara, count[i].count);
		}
	}
	
	return 0;
}
