#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int num_case;
int grade[1010];

int main(int argc, char **argv)
{
	int cas;
	int i, n;
	double sum;
	int count;

	scanf("%d", &num_case);

	for (cas = 0; cas < num_case; cas++)
	{
		scanf("%d", &n);

		sum = 0;
		for (i = 0; i < n; i++)
		{
			scanf("%d", grade + i);
			sum += (double)(grade[i]);
		}

		sum /= (double)n;

		count = 0;
		for (i = 0; i < n; i++)
		{
			if (((double)grade[i]) > sum)
			{
				count++;
			}
		}

		printf("%.3f%%\n", (((double)count) / ((double)n)) * ((double)100));
	}

	return 0;
}
