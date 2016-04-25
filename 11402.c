#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	long l, r;
	long num[2];
	char flag;
} NODE;

NODE tree[2100000];

char pirate[1024010];
char str[100];
long count;

void build_tree(long cur, long l, long r)
{
	long mid = (l + r) / 2;

	tree[cur].l = l;
	tree[cur].r = r;
	tree[cur].num[0] = 0;
	tree[cur].num[1] = 0;
	tree[cur].flag = 2;

	if (l == r)
	{
		(tree[cur].num[pirate[l] - '0'])++;
		tree[cur].flag = pirate[l] - '0';
		return;
	}

	build_tree(2 * cur, l, mid);
	build_tree(2 * cur + 1, mid + 1, r);

	tree[cur].num[0] = tree[2 * cur].num[0] + tree[2 * cur + 1].num[0];
	tree[cur].num[1] = tree[2 * cur].num[1] + tree[2 * cur + 1].num[1];
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
		tree[cur].num[num] = r - l + 1;
		tree[cur].num[num ^ 1] = 0;
		tree[cur].flag = num;
		return;
	}

	if (tree[cur].flag < 2)
	{
		tree[2 * cur].flag = tree[cur].flag;
		tree[2 * cur].num[tree[cur].flag] = tree[2 * cur].r - tree[2 * cur].l + 1;
		tree[2 * cur].num[(tree[cur].flag) ^ 1] = 0;

		tree[2 * cur + 1].flag = tree[cur].flag;
		tree[2 * cur + 1].num[tree[cur].flag] = tree[2 * cur + 1].r - tree[2 * cur + 1].l + 1;
		tree[2 * cur + 1].num[(tree[cur].flag) ^ 1] = 0;

		tree[cur].flag = 2;
	}

	if (l <= tree[2 * cur].r)
	{
		change_tree(2 * cur, l, min(r, tree[2 * cur].r), num);
	}

	if (r >= tree[2 * cur + 1].l)
	{
		change_tree(2 * cur + 1, max(l, tree[2 * cur + 1].l), r, num);
	}

	tree[cur].num[0] = tree[2 * cur].num[0] + tree[2 * cur + 1].num[0];
	tree[cur].num[1] = tree[2 * cur].num[1] + tree[2 * cur + 1].num[1];
}

void inverse_tree(long cur, long l, long r)
{
	long t;

	if (tree[cur].l == l && tree[cur].r == r && tree[cur].flag < 2)
	{
		t = tree[cur].num[0];
		tree[cur].num[0] = tree[cur].num[1];
		tree[cur].num[1] = t;
		tree[cur].flag ^= 1;
		return;
	}

	if (tree[cur].flag < 2)
	{
		tree[2 * cur].flag = tree[cur].flag;
		tree[2 * cur].num[tree[cur].flag] = tree[2 * cur].r - tree[2 * cur].l + 1;
		tree[2 * cur].num[(tree[cur].flag) ^ 1] = 0;

		tree[2 * cur + 1].flag = tree[cur].flag;
		tree[2 * cur + 1].num[tree[cur].flag] = tree[2 * cur + 1].r - tree[2 * cur + 1].l + 1;
		tree[2 * cur + 1].num[(tree[cur].flag) ^ 1] = 0;

		tree[cur].flag = 2;
	}

	if (l <= tree[2 * cur].r)
	{
		inverse_tree(2 * cur, l, min(r, tree[2 * cur].r));
	}

	if (r >= tree[2 * cur + 1].l)
	{
		inverse_tree(2 * cur + 1, max(l, tree[2 * cur + 1].l), r);
	}

	tree[cur].num[0] = tree[2 * cur].num[0] + tree[2 * cur + 1].num[0];
	tree[cur].num[1] = tree[2 * cur].num[1] + tree[2 * cur + 1].num[1];
}

long query_tree(long cur, long l, long r, int num)
{
	long ans = 0;

	if (tree[cur].l == l && tree[cur].r == r)
	{
		return tree[cur].num[num];
	}

	if (tree[cur].flag < 2)
	{
		tree[2 * cur].flag = tree[cur].flag;
		tree[2 * cur].num[tree[cur].flag] = tree[2 * cur].r - tree[2 * cur].l + 1;
		tree[2 * cur].num[(tree[cur].flag) ^ 1] = 0;

		tree[2 * cur + 1].flag = tree[cur].flag;
		tree[2 * cur + 1].num[tree[cur].flag] = tree[2 * cur + 1].r - tree[2 * cur + 1].l + 1;
		tree[2 * cur + 1].num[(tree[cur].flag) ^ 1] = 0;

		tree[cur].flag = 2;
	}

	if (l <= tree[2 * cur].r)
	{
		ans += query_tree(2 * cur, l, min(r, tree[2 * cur].r), num);
	}

	if (r >= tree[2 * cur + 1].l)
	{
		ans += query_tree(2 * cur + 1, max(l, tree[2 * cur + 1].l), r, num);
	}

	return ans;
}

int main(int argc, char **argv)
{
	int num_case;
	int cas;
	int m;
	int t;
	int i;
	int j;
	int k;
	int q;
	char ch;
	long x, y;
	int c;

	scanf("%d", &num_case);

	for (cas = 1; cas <= num_case; cas++)
	{
		count = 0;
		scanf("%d", &m);

		for (i = 0; i < m; i++)
		{
			scanf("%d", &t);
			getchar();
			gets(str);

			for (j = 0; j < t; j++)
			{
				for (k = 0; k < strlen(str); k++)
				{
					pirate[count++] = str[k];
				}
			}
		}

		build_tree(1, 0, count - 1);

		printf("Case %d:\n", cas);

		scanf("%d", &q);
		getchar();
		c = 0;

		for (i = 0; i < q; i++)
		{
			scanf("%c %ld %ld", &ch, &x, &y);
			getchar();
			switch (ch)
			{
				case 'F':
					change_tree(1, x, y, 1);
					break;
				case 'E':
					change_tree(1, x, y, 0);
					break;
				case 'I':
					inverse_tree(1, x, y);
					break;
				case 'S':
					printf("Q%d: %ld\n", ++c, query_tree(1, x, y, 1));
			}
		}
	}

	return 0;
}
