#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int h, d;
	int flag;
	double ans;
	double u;
	double f;
	int day;

	while (scanf("%d %lf %d %lf", &h, &u, &d, &f) == 4)
	{
		if (!h)
		{
			break;
		}

		f = u * f / 100.0;

		flag = 0;
		ans = 0;
		for (day = 1; ; day++)
		{
			ans += u;
			if (ans > h)
			{
				flag = 1;
				break;
			}

			ans -= d;
			if (ans < 0)
			{
				break;
			}

			u -= f;
			if (u < 0)
			{
				u = 0;
			}
		}

		if (flag)
		{
			printf("success on day %d\n", day);
		}
		else
		{
			printf("failure on day %d\n", day);
		}
	}
	
	return 0;
}
