#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int graph[30][30];

char city1[1000], city2[1000];
char output[50];

int dist[30][30];
int next[30][30];

int num_case, num_edge, num_query;

void floyd()
{
	int i, j, k;
	
	for (i = 0; i < 30; i++)
	{
		for (j = 0; j < 30; j++)
		{
			if (graph[i][j] > 0)
			{
				dist[i][j] = graph[i][j];
				next[i][j] = j;
			}
			else
			{
				dist[i][j] = 1000;
				next[i][j] = -1;
			}
		}
	}
	
	for (k = 0; k < 30; k++)
	{
		for (i = 0; i < 30; i++)
		{
			for (j = 0; j < 30; j++)
			{
				if (dist[i][k] + dist[k][j] < dist[i][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
					next[i][j] = next[i][k];
				}
			}
		}
	}
}

void query()
{
	int i, x, y, l;
	
	for (i = 0; i < num_query; i++)
	{
		scanf("%s %s", city1, city2);
		
		x = city1[0] - 'A';
		y = city2[0] - 'A';
		
		output[0] = x + 'A';
		l = 1;
		
		while (x != y)
		{
			x = next[x][y];
			
			output[l++] = x + 'A';
		}

		output[l] = 0;

		printf("%s\n", output);
	}
}

int main(int argc, char **argv)
{
	int i, j, x, y;
	
	scanf("%d", &num_case);
		
	for (i = 0; i < num_case; i++)
	{
		gets(city1);
				
		scanf("%d %d", &num_edge, &num_query);
		
		for (x = 0; x < 30; x++)
		{
			for (y = 0; y < 30; y++)
			{
				graph[x][y] = -1;
			}
		}

		for (j = 0; j < num_edge; j++)
		{
			scanf("%s %s", city1, city2);
			
			x = city1[0] - 'A';
			y = city2[0] - 'A';
			
			graph[x][y] = 1;
			graph[y][x] = 1;
		}
	
		floyd();

		query();
		
		if (i < num_case - 1)
		{
			printf("\n");
		}
	}
	
	return 0;
}
