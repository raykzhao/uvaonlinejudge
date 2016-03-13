#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct gnode
{
	int y;
	struct gnode *next;
} GNODE;

GNODE *g_head[205], *g_tail[205];

int queue[40000];

int g_color[205];

int n;

int flag;

void do_graph()
{
	int q_head = 0, q_tail = 0;
	int i, x;
	GNODE *cur;
	
	queue[q_tail++] = 0;
	
	for (i = 0; i < n; i++)
	{
		g_color[i] = -1;
	}
	
	g_color[0] = 0;
	
	while (q_head < q_tail)
	{
		x = queue[q_head];
		cur = g_head[x]->next;
		
		while (cur != NULL)
		{
			if (g_color[cur->y] == -1)
			{
				g_color[cur->y] = (g_color[x] ^ 1);
				queue[q_tail++] = cur->y;
			}
			else if (g_color[cur->y] == g_color[x])
			{
				flag = 1;
				return;
			}
			
			cur = cur->next;
		}
		
		q_head++;
	}
}

int main(int argc, char **argv)
{
	int p, q;
	int i, n1;
	int max, maxi;
	int cur = 0;
	
	scanf("%d", &n);
	
	while (n)
	{
		for (i = 0; i < n; i++)
		{
			g_head[i] = malloc(sizeof(GNODE));
			g_head[i]->y = 0;
			g_head[i]->next = NULL;
			
			g_tail[i] = g_head[i];
		}
		
		scanf("%d", &n1);
		
		for (i = 0; i < n1; i++)
		{
			scanf("%d %d", &p, &q);

			g_tail[p]->next = malloc(sizeof(GNODE));
			g_tail[p]->next->y = q;
			g_tail[p]->next->next = NULL;			
			g_tail[p] = g_tail[p]->next;

			g_tail[q]->next = malloc(sizeof(GNODE));
			g_tail[q]->next->y = p;
			g_tail[q]->next->next = NULL;			
			g_tail[q] = g_tail[q]->next;
		}

		flag = 0;
		
		do_graph();
		
		if (flag)
		{
			printf("NOT BICOLORABLE.\n");
		}
		else
		{
			printf("BICOLORABLE.\n");
		}
		
		scanf("%d", &n);
	}
	
	return 0;
}
