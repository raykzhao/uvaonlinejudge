#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct xy
{
	double x, y;
} XY;

XY points[110];
XY h[110];

int n;

double ccw(XY p1, XY p2, XY p3)
{
	return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

int do_convex()
{
	int i, t, k = 0;

	for (i = 0; i < n; i++)
	{
		while (k >= 2 && ccw(h[k - 2], h[k - 1], points[i]) <= 0)
		{
			k--;
		}

		h[k].x = points[i].x;
		h[k++].y = points[i].y;
	}

	t = k + 1;
	for (i = n - 2; i >= 0; i--)
	{
		while (k >= t && ccw(h[k - 2], h[k - 1], points[i]) <= 0)
		{
			k--;
		}

		h[k].x = points[i].x;
		h[k++].y = points[i].y;
	}

	return k;
}

int compar(const void *a, const void *b)
{
	XY aa = *((XY *)a), bb = *((XY *)b);

	if (aa.x < bb.x)
	{
		return -1;
	}
	else if (aa.x == bb.x)
	{
		if (aa.y < bb.y)
		{
			return -1;
		}
		else if (aa.y == bb.y)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	else
	{
		return 1;
	}
}

int main(int argc, char **argv)
{
	int i;
	double s_in;
	double s_out;
	int c_n;
	int cas;

	for (cas = 1; scanf("%d", &n) == 1; cas++)
	{
		if (!n)
		{
			break;
		}

		for (i = 0; i < n; i++)
		{
			scanf("%lf %lf", &(points[i].x), &(points[i].y));
		}

		points[n].x = points[0].x;
		points[n].y = points[0].y;

		s_in = 0;
		for (i = 0; i < n; i++)
		{
			s_in += (points[i].x * points[i + 1].y) - (points[i].y * points[i + 1].x);
		}
		s_in = fabs(s_in);
		
		qsort(points, n, sizeof(XY), compar);

		c_n = do_convex();

		s_out = 0;
		for (i = 0; i < c_n - 1; i++)
		{
			s_out += (h[i].x * h[i + 1].y) - (h[i].y * h[i + 1].x);
		}
		s_out = fabs(s_out);

		printf("Tile #%d\n", cas);
		printf("Wasted Space = %.2f %%\n", (s_out - s_in) / s_out * 100.0);
		printf("\n");
	}

	return 0;
}
