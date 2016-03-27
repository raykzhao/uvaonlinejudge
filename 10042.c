#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int is_prime[100010];
int all_prime[100010];
int count_prime;

int num_case;

void sieve()
{
	int i;
	int j;

	is_prime[2] = 1;

	for (i = 3; i <= 100000; i += 2)
	{
		is_prime[i] = 1;
	}

	for (i = 3; i <= (int)(sqrt(100000)); i += 2)
	{
		if (is_prime[i])
		{
			for (j = i * i; j <= 100000; j += 2 * i)
			{
				is_prime[j] = 0;
			}
		}
	}

	all_prime[count_prime++] = 2;

	for (i = 3; i <= 100000; i += 2)
	{
		if (is_prime[i])
		{
			all_prime[count_prime++] = i;
		}
	}
}

int check_prime(int x)
{
	int i;

	if (x <= 100000)
	{
		return is_prime[x];
	}

	if (!(x % 2))
	{
		return 0;
	}

	for (i = 0; i < count_prime; i++)
	{
		if (all_prime[i] < x)
		{
			if (!(x % all_prime[i]))
			{
				return 0;
			}
		}
		else
		{
			break;
		}
	}

	return 1;
}

int calc_sum(int x)
{
	int sum = 0;

	while (x)
	{
		sum += x % 10;
		x /= 10;
	}

	return sum;
}

int check_smith(int x)
{
	int i;
	int sum = 0;
	int sum1;
	
	if (check_prime(x))
	{
		return 0;
	}

	sum1 = calc_sum(x);

	while (!check_prime(x))
	{
		for (i = 0; i < count_prime; i++)
		{
			if (all_prime[i] < x)
			{
				if (!(x % all_prime[i]))
				{
					x /= all_prime[i];
					sum += calc_sum(all_prime[i]);
					break;
				}
			}
			else
			{
				break;
			}
		}
	}

	sum += calc_sum(x);

	if (sum == sum1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main(int argc, char **argv)
{
	int i;
	int cas;
	int x;

	sieve();
	
	scanf("%d", &num_case);

	for (cas = 0; cas < num_case; cas++)
	{
		scanf("%d", &x);
		
		while (!check_smith(++x));

		printf("%d\n", x);
	}

	return 0;
}
