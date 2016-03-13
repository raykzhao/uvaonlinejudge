#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct gnode
{
	int y;
	struct gnode *next;
} GNODE;

GNODE *g_head[105], *g_tail[105];

int queue[10000];

int g_len[105];

int n, s;

void do_graph()
{
	int q_head = 0, q_tail = 0;
	int i, x;
	GNODE *cur;
	
	queue[q_tail++] = s;
	
	for (i = 1; i <= n; i++)
	{
		g_len[i] = 0;
	}
	
	while (q_head < q_tail)
	{
		x = queue[q_head];
		cur = g_head[x]->next;
		
		while (cur != NULL)
		{
			if (g_len[x] + 1 > g_len[cur->y])
			{
				g_len[cur->y] = g_len[x] + 1;
				queue[q_tail++] = cur->y;
			}
			
			cur = cur->next;
		}
		
		q_head++;
	}
}

int main(int argc, char **argv)
{
	int p, q;
	int i;
	int max, maxi;
	int cur = 0;
	
	scanf("%d", &n);
	
	while (n)
	{
		for (i = 1; i <= n; i++)
		{
			g_head[i] = malloc(sizeof(GNODE));
			g_head[i]->y = 0;
			g_head[i]->next = NULL;
			
			g_tail[i] = g_head[i];
		}
		
		scanf("%d", &s);
		
		scanf("%d %d", &p, &q);
		
		while (p || q)
		{
			g_tail[p]->next = malloc(sizeof(GNODE));
			g_tail[p]->next->y = q;
			g_tail[p]->next->next = NULL;
			
			g_tail[p] = g_tail[p]->next;

			scanf("%d %d", &p, &q);			
		}

		do_graph();
		
		max = 0;
		maxi = s;
		
		for (i = n; i >= 1; i--)
		{
			if (g_len[i] >= max)
			{
				max = g_len[i];
				maxi = i;
			}
		}
		
		printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", ++cur, s, max, maxi);
		
		scanf("%d", &n);
	}
	
	return 0;
}
