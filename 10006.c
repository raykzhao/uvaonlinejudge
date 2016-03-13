#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int is_prime[65005];
int n;

void all_prime()
{
	int i, j;
	for (i = 4; i <= 65000; i += 2)
	{
		is_prime[i] = 1;
	}
	
	for (i = 3; i <= sqrt(65000); i += 2)
	{
		if (!is_prime[i])
		{
			for (j = i * i; j <= 65000; j += (2 * i))
			{
				is_prime[j] = 1;			
			}
		}
	}
}

int check(int base)
{
	int power = n;
	
	unsigned long long cur = base;
	unsigned long long res = 1;
	
	while (power)
	{
		if (power & 1)
		{
			res = (res * cur) % n;
		}
		
		cur = (cur * cur) % n;
		
		power >>= 1;
	}
	
	if (res == base)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int main(int argc, char **argv)
{
	int i, flag;
	
	all_prime();
	
	scanf("%d", &n);
	
	while (n)
	{
		if (!is_prime[n])
		{
			printf("%d is normal.\n", n);
		}
		else
		{
			for (i = 2; i <= n - 1; i++)
			{
				flag = check(i);
				if (flag)
				{
					break;
				}
			}
			
			if (flag)
			{
				printf("%d is normal.\n", n);
			}
			else
			{
				printf("The number %d is a Carmichael number.\n", n);
			}
		}
		
		scanf("%d", &n);
	}
	
	return 0;
}
