#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	long l, r;
	int num;
} NODE;

NODE tree[1700000];

long n, m;
int num[100010];

void build_tree(long cur, long l, long r)
{
	long mid = (l + r) / 2;

	tree[cur].l = l;
	tree[cur].r = r;

	if (l == r)
	{
		tree[cur].num = num[l];
		return;
	}

	build_tree(2 * cur, l, mid);
	build_tree(2 * cur + 1, mid + 1, r);

	tree[cur].num = tree[2 * cur].num * tree[2 * cur + 1].num;
}

long min(long a, long b)
{
	return (a < b) ? a : b;
}

long max(long a, long b)
{
	return (a > b) ? a : b;
}

void change_tree(long cur, long l, long r, int num)
{
	if (tree[cur].l == l && tree[cur].r == r)
	{
		tree[cur].num = num;
		return;
	}

	if (l <= tree[2 * cur].r)
	{
		change_tree(2 * cur, l, min(r, tree[2 * cur].r), num);
	}
	
	if (r >= tree[2 * cur + 1].l)
	{
		change_tree(2 * cur + 1, max(l, tree[2 * cur + 1].l), r, num);
	}

	tree[cur].num = tree[2 * cur].num * tree[2 * cur + 1].num;
}

int query_tree(long cur, long l, long r)
{
	int ans = 1;

	if (tree[cur].l == l && tree[cur].r == r)
	{
		return tree[cur].num;
	}

	if (l <= tree[2 * cur].r)
	{
		ans *= query_tree(2 * cur, l, min(r, tree[2 * cur].r));
	}

	if (r >= tree[2 * cur + 1].l)
	{
		ans *= query_tree(2 * cur + 1, max(l, tree[2 * cur + 1].l), r);
	}

	return ans;
}

int main(int argc, char **argv)
{
	long i;
	char ch;
	long l, r;
	long x;

	while (scanf("%ld %ld", &n, &m) == 2)
	{
		for (i = 0; i < n; i++)
		{
			scanf("%d ", num + i);

			if (num[i] < 0)
			{
				num[i] = -1;
			}
			else if (num[i] > 0)
			{
				num[i] = 1;
			}
		}

		build_tree(1, 0, n - 1);

		for (i = 0; i < m; i++)
		{
			scanf("%c %ld %ld", &ch, &l, &r);
			getchar();

			l--;
			if (ch == 'C')
			{
				if (r < 0)
				{
					r = -1;
				}
				else if (r > 0)
				{
					r = 1;
				}

				change_tree(1, l, l, r);
			}
			else if (ch == 'P')
			{
				r--;
				x = query_tree(1, l, r);

				if (x < 0)
				{
					putchar('-');
				}
				else if (!x)
				{
					putchar('0');
				}
				else
				{
					putchar('+');
				}
			}
		}

		printf("\n");
	}

	return 0;
}
