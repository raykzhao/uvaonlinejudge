#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int num_case;
char str[1010];
int freq[30];

int main(int argc, char **argv)
{
	int cas;
	int i;
	int first;
	int j;

	scanf("%d", &num_case);
	getchar();

	for (cas = 0; cas < num_case; cas++)
	{
		gets(str);

		memset(freq, 0, sizeof(freq));

		for (i = 0; i < strlen(str); i++)
		{
			freq[str[i] - 'a']++;
		}

		for (first = 0; first < 26 && (!freq[first]); first++);

		for (i = first + 1; i < 26; i++)
		{
			if (freq[i])
			{
				freq[first] += freq[i] - 1;
				freq[i] = 1;
			}
		}

		for (i = 0; i < 26; i++)
		{
			if (freq[i])
			{
				for (j = 0; j < freq[i]; j++)
				{
					printf("%c", i + 'a');
				}
			}
		}
		printf("\n");
	}

	return 0;
}
