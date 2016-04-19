#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	int num_case;
	int x, xx;
	int i;
	int flag;
	int cas;

	puts("Lumberjacks:");

	scanf("%d", &num_case);

	for (cas = 0; cas < num_case; cas++)
	{
		flag = -1;
		scanf("%d", &x);
		for (i = 1; i < 10; x = xx, i++)
		{
			scanf("%d", &xx);

			if (flag == -1)
			{
				if (x < xx)
				{
					flag = 0;
				}
				else
				{
					flag = 1;
				}

				continue;
			}

			if (!flag)
			{
				if (x < xx)
				{
					continue;
				}
				else
				{
					puts("Unordered");
					flag = 2;
				}
			}
			else if (flag == 1)
			{
				if (x > xx)
				{
					continue;
				}
				else
				{
					puts("Unordered");
					flag = 2;
				}
			}
		}

		if (flag != 2)
		{
			puts("Ordered");
		}
	}

	return 0;
}
