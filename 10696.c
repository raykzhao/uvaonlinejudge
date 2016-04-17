#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long f91(long n)
{
	if (n <= 100)
	{
		return f91(f91(n + ((long)11)));
	}
	else
	{
		return (n - ((long)10));
	}
}

int main(int argc, char **argv)
{
	long n;

	while (scanf("%ld", &n) == 1)
	{
		if (!n)
		{
			break;
		}

		printf("f91(%ld) = %ld\n", n, f91(n));
	}

	return 0;
}
