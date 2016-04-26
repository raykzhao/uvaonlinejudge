#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <utility>

using namespace std;

typedef struct node
{
	int x1, y1, x2, y2;
	long max, min;
} NODE;

NODE tree[1100000];

long num[510][510];

int n;

long max4(long a, long b, long c, long d)
{
	long ans = a;
	if (b > ans)
		ans = b;
	if (c > ans)
		ans = c;
	if (d > ans)
		ans = d;

	return ans;
}

long min4(long a, long b, long c, long d)
{
	long ans = a;
	if (b < ans)
		ans = b;
	if (c < ans)
		ans = c;
	if (d < ans)
		ans = d;

	return ans;
}

void build_tree(long cur, long x1, long y1, long x2, long y2)
{
	tree[cur].x1 = x1;
	tree[cur].y1 = y1;
	tree[cur].x2 = x2;
	tree[cur].y2 = y2;

	if ((x1 > x2) || (y1 > y2))
	{
		tree[cur].max = -1000000000;
		tree[cur].min = 1000000000;
		return;
	}

	if ((x1 == x2) && (y1 == y2))
	{
		tree[cur].max = num[x1][y1];
		tree[cur].min = num[x1][y1];
		return;
	}

	long midX = (x1 + x2) / 2;
	long midY = (y1 + y2) / 2;

	build_tree(4 * cur + 1, x1, y1, midX, midY);
	build_tree(4 * cur + 2, x1, midY + 1, midX, y2);
	build_tree(4 * cur + 3, midX + 1, y1, x2, midY);
	build_tree(4 * cur + 4, midX + 1, midY + 1, x2, y2);

	tree[cur].max = max4(tree[4 * cur + 1].max, tree[4 * cur + 2].max, tree[4 * cur + 3].max, tree[4 * cur + 4].max);
	tree[cur].min = min4(tree[4 * cur + 1].min, tree[4 * cur + 2].min, tree[4 * cur + 3].min, tree[4 * cur + 4].min);
}

long max2(long a, long b)
{
	return (a > b) ? a : b;
}

long min2(long a, long b)
{
	return (a < b) ? a : b;
}

void change_tree(long cur, long x1, long y1, long x2, long y2, long num)
{
	if ((tree[cur].x1 > tree[cur].x2) || (tree[cur].y1 > tree[cur].y2))
	{
		return;
	}

	if ((tree[cur].x1 == x1) && (tree[cur].y1 == y1) && (tree[cur].x2 == x2) && (tree[cur].y2 == y2))
	{
		tree[cur].max = num;
		tree[cur].min = num;
		return;
	}

	if ((x1 <= tree[4 * cur + 1].x2) && (y1 <= tree[4 * cur + 1].y2))
	{
		change_tree(4 * cur + 1, x1, y1, min2(x2, tree[4 * cur + 1].x2), min2(y2, tree[4 * cur + 1].y2), num);
	}

	if ((x1 <= tree[4 * cur + 2].x2) && (y2 >= tree[4 * cur + 2].y1))
	{
		change_tree(4 * cur + 2, x1, max2(y1, tree[4 * cur + 2].y1), min2(x2, tree[4 * cur + 2].x2), y2, num);
	}

	if ((x2 >= tree[4 * cur + 3].x1) && (y1 <= tree[4 * cur + 3].y2))
	{
		change_tree(4 * cur + 3, max2(x1, tree[4 * cur + 3].x1), y1, x2, min2(y2, tree[4 * cur + 3].y2), num);
	}

	if ((x2 >= tree[4 * cur + 4].x1) && (y2 >= tree[4 * cur + 4].y1))
	{
		change_tree(4 * cur + 4, max2(x1, tree[4 * cur + 4].x1), max2(y1, tree[4 * cur + 4].y1), x2, y2, num);
	}

	tree[cur].max = max4(tree[4 * cur + 1].max, tree[4 * cur + 2].max, tree[4 * cur + 3].max, tree[4 * cur + 4].max);
	tree[cur].min = min4(tree[4 * cur + 1].min, tree[4 * cur + 2].min, tree[4 * cur + 3].min, tree[4 * cur + 4].min);
}

pair <long, long> query_tree(long cur, long x1, long y1, long x2, long y2)
{
	if ((tree[cur].x1 > tree[cur].x2) || (tree[cur].y1 > tree[cur].y2))
	{
		return (make_pair(-1000000000, 1000000000));
	}

	if ((tree[cur].x1 == x1) && (tree[cur].y1 == y1) && (tree[cur].x2 == x2) && (tree[cur].y2 == y2))
	{
		return (make_pair(tree[cur].max, tree[cur].min));
	}

	pair <long, long> ret[4];
	
	for (int i = 0; i < 4; i++)
	{
		ret[i] = make_pair(-1000000000, 1000000000);
	}

	if ((x1 <= tree[4 * cur + 1].x2) && (y1 <= tree[4 * cur + 1].y2))
	{
		ret[0] = query_tree(4 * cur + 1, x1, y1, min2(x2, tree[4 * cur + 1].x2), min2(y2, tree[4 * cur + 1].y2));
	}

	if ((x1 <= tree[4 * cur + 2].x2) && (y2 >= tree[4 * cur + 2].y1))
	{
		ret[1] = query_tree(4 * cur + 2, x1, max2(y1, tree[4 * cur + 2].y1), min2(x2, tree[4 * cur + 2].x2), y2);
	}

	if ((x2 >= tree[4 * cur + 3].x1) && (y1 <= tree[4 * cur + 3].y2))
	{
		ret[2] = query_tree(4 * cur + 3, max2(x1, tree[4 * cur + 3].x1), y1, x2, min2(y2, tree[4 * cur + 3].y2));
	}


	if ((x2 >= tree[4 * cur + 4].x1) && (y2 >= tree[4 * cur + 4].y1))
	{
		ret[3] = query_tree(4 * cur + 4, max2(x1, tree[4 * cur + 4].x1), max2(y1, tree[4 * cur + 4].y1), x2, y2);
	}

	return (make_pair(max4(ret[0].first, ret[1].first, ret[2].first, ret[3].first), min4(ret[0].second, ret[1].second, ret[2].second, ret[3].second)));
}

int main(int argc, char **argv)
{
	long q;
	char ch;
	int x1, y1, x2, y2;
	long num2;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%ld", &(num[i][j]));
		}
	}

	build_tree(0, 0, 0, n - 1, n - 1);

	scanf("%ld", &q);
	getchar();

	pair <long, long> ans;
	for (long i = 0; i < q; i++)
	{
		scanf("%c %d %d", &ch, &x1, &y1);
		
		switch (ch)
		{
			case 'q':
				scanf("%d %d", &x2, &y2);
				getchar();
				ans = query_tree(0, x1 - 1, y1 - 1, x2 - 1, y2 - 1);
				printf("%ld %ld\n", ans.first, ans.second);
				break;
			case 'c':
				scanf("%ld", &num2);
				getchar();
				change_tree(0, x1 - 1, y1 - 1, x1 - 1, y1 - 1, num2);
		}
	}

	return 0;
}
