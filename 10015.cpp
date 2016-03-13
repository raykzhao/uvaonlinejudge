#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>

using namespace std;

int is_prime[50000];
int list_prime[3510];
int prime_count;

vector<int> person;

void all_prime()
{
	long int i, j;
	for (i = 4; i <= 40000; i += 2)
	{
		is_prime[i] = 1;
	}
	
	for (i = 3; i <= sqrt(40000); i += 2)
	{
		if (!is_prime[i])
		{
			for (j = i * i; j <= 40000; j += (2 * i))
			{
				is_prime[j] = 1;			
			}
		}
	}

	for (i = 2; (i <= 40000) && (prime_count <= 3501); i++)
	{
		if (!is_prime[i])
		{
			list_prime[prime_count++] = i;
		}
	}
}

int main(int argc, char **argv)
{
	int n;
	int i, j, lastj, cur_prime, count;
	
	all_prime();
	
	scanf("%d", &n);

	while (n)
	{
		person.clear();
		
		for (i = 1; i <= n; i++)
		{
			person.push_back(i);
		}
		
		lastj = 0;
		
		for (i = 0; i < n - 1; i++)
		{
			cur_prime = list_prime[i];
			
			lastj = ((lastj + cur_prime - 1) % (person.size()));
			person.erase(person.begin() + lastj);
			
		}
		
		printf("%d\n", person[0]);
		
		scanf("%d", &n);
	}
	return 0;
}
