#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long long n;

void do_output(unsigned long long n)
{
	unsigned long long kuti1 = n / ((unsigned long long)10000000);
	unsigned long long kuti2 = n % ((unsigned long long)10000000);

	unsigned long long lakh1 = kuti2 / ((unsigned long long)100000);
	unsigned long long lakh2 = kuti2 % ((unsigned long long)100000);

	unsigned long long hajar1 = lakh2 / ((unsigned long long)1000);
	unsigned long long hajar2 = lakh2 % ((unsigned long long)1000);

	unsigned long long shata1 = hajar2 / ((unsigned long long)100);
	unsigned long long shata2 = hajar2 % ((unsigned long long)100);

	if (kuti1)
	{
		do_output(kuti1);
		printf(" kuti");
	}

	if (lakh1)
	{
		printf(" %llu lakh", lakh1);
	}

	if (hajar1)
	{
		printf(" %llu hajar", hajar1);
	}

	if (shata1)
	{
		printf(" %llu shata", shata1);
	}

	if (shata2)
	{
		printf(" %llu", shata2);
	}
}

int main(int argc, char **argv)
{
	int cas = 1;

	while (scanf("%llu", &n) == 1)
	{
		printf("%4d.", cas);

		if (!n)
		{
			printf(" 0");
		}
		else
		{
			do_output(n);
		}

		printf("\n");

		cas++;
	}

	return 0;
}
