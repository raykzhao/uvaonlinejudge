#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[100010];
char up[100010], down[100010];
char newstr[100010];
char str1[100010];

int main(int argc, char **argv)
{
	long n;
	long long t;
	char di;
	long i;
	long long x;

	while (scanf("%ld %lld %c", &n, &t, &di) == 3)
	{
		getchar();
		gets(up);
		gets(str);
		gets(down);

		for (i = 0; i < n; i++)
		{
			newstr[i] = str[2 * i + 1];
		}

		x = t % n;

		if (x)
		{
			if (di == 'R')
			{
				for (i = x; i < n; i++)
				{
					str1[i] = newstr[i - x];
				}

				for (i = n - x; i < n; i++)
				{
					str1[i - (n - x)] = newstr[i];
				}

				for (i = 0; i < n; i++)
				{
					str[2 * i + 1] = str1[i];
				}
			}
			else
			{
				for (i = n - x; i < n; i++)
				{
					str1[i] = newstr[i - (n - x)];
				}

				for (i = x; i < n; i++)
				{
					str1[i - x] = newstr[i];
				}

				for (i = 0; i < n; i++)
				{
					str[2 * i + 1] = str1[i];
				}
			}
		}

		puts(up);
		puts(str);
		puts(down);
	}

	return 0;
}
