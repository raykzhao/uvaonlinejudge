#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int num_case;

int main(int argc, char **argv)
{
	int cas;
	int n, i; 
	double a0, an1, ci;
	double sum;
	
	scanf("%d", &num_case);
	
	for (cas = 0; cas < num_case; cas++)
	{
		scanf("%d", &n);
		
		scanf("%lf %lf", &a0, &an1);
		
		an1 /= ((double)(n + 1));
		a0 *= (((double)(n)) / ((double)(n + 1)));
		
		sum = 0.0;
		
		for (i = 0; i < n; i++)
		{
			scanf("%lf", &ci);
			
			sum += ((((double)(n - i)) / ((double)(n + 1))) * ci);
		}
		
		sum *= 2.0;
		
		printf("%.2f\n", a0 + an1 - sum);
		
		if (cas < num_case - 1)
		{
			printf("\n");
		}
	}
	
	return 0;
}
