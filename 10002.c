#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct xy
{
	double x, y;
} XY;

XY points[110];

XY convex[110];

int n;

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

double ccw(XY p1, XY p2, XY p3)
{
	return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

int do_convex()
{
	int i, t, k = 0;

	for (i = 0; i < n; i++)
	{
		while (k >= 2 && ccw(convex[k - 2], convex[k - 1], points[i]) <= 0)
		{
			k--;
		}

		convex[k].x = points[i].x;
		convex[k++].y = points[i].y;
	}

	t = k + 1;
	for (i = n - 2; i >= 0; i--)
	{
		while (k >= t && ccw(convex[k - 2], convex[k - 1], points[i]) <= 0)
		{
			k--;
		}

		convex[k].x = points[i].x;
		convex[k++].y = points[i].y;
	}

	return k;
}

int main(int argc, char **argv)
{
	int i;
	double a, cx, cy;
	double cc;
	int nn;

	while (scanf("%d", &n) == 1)
	{
		if (n < 3)
		{
			break;
		}

		for (i = 0; i < n; i++)
		{
			scanf("%lf %lf", &(points[i].x), &(points[i].y));
		}

		qsort(points, n, sizeof(XY), compar);

		nn = do_convex();

		a = 0.0;
		cx = 0.0;
		cy = 0.0;
		for (i = 0; i < nn - 1; i++)
		{
			cc = convex[i].x * convex[i + 1].y - convex[i + 1].x * convex[i].y;
			cx += (convex[i].x + convex[i + 1].x) * cc;
			cy += (convex[i].y + convex[i + 1].y) * cc;
			a += cc;
		}

		printf("%.3f %.3f\n", cx / a / 3.0, cy / a / 3.0);
	}

	return 0;
}
