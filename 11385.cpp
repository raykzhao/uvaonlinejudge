#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>

using namespace std;

int numCase;

map <long, int> fib;
long encode[110];

char strInput[110];
char strOri[110];
char strOutput[110];

void genFib()
{
	fib[1] = 0;
	fib[2] = 1;

	long x = 1, y = 2;

	for (int i = 2; i < 45; i++)
	{
		long z = x + y;
		
		fib[z] = i;

		x = y;
		y = z;
	}
}

int main(int argc, char **argv)
{
	genFib();

	scanf("%d", &numCase);

	for (int cas = 0; cas < numCase; cas++)
	{
		int n;
		scanf("%d", &n);

		for (int i = 0; i < n; i++)
		{
			scanf("%ld", encode + i);
		}

		getchar();
		gets(strInput);

		memset(strOri, 0, sizeof(strOri));
		for (int i = 0, strOriLen = 0; i < strlen(strInput); i++)
		{
			if ((strInput[i] >= 'A') && (strInput[i] <= 'Z'))
			{
				strOri[strOriLen++] = strInput[i];
			}
		}

		memset(strOutput, ' ', sizeof(strOutput));

		for (int i = 0; i < n; i++)
		{
			strOutput[fib[encode[i]]] = strOri[i];
		}

		int lastSpace;
		for (lastSpace = 101; (lastSpace >= 0) && (strOutput[lastSpace] == ' '); lastSpace--);

		strOutput[lastSpace + 1] = 0;

		printf("%s\n", strOutput);
	}

	return 0;
}
