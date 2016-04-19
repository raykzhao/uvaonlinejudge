#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <set>

using namespace std;

long edge[3];

set <long> edgeSet;

int compar(const void *a, const void *b)
{
	long aa = *((long *)a), bb = *((long *)b);
	
	if (aa < bb)
	{
		return -1;
	}
	else if (aa == bb)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int main(int argc, char **argv)
{
	int numCase;
	
	scanf("%d", &numCase);

	for (int cas = 1; cas <= numCase; cas++)
	{
		scanf("%ld %ld %ld", edge, edge + 1, edge + 2);
		
		qsort(edge, 3, sizeof(long), compar);

		printf("Case %d: ", cas);
		if (edge[0] < 0)
		{
			printf("Invalid\n");
			continue;
		}

		long long edgeSum = ((long long)edge[0]) + ((long long)edge[1]);
		if (edgeSum > ((long long)edge[2]))
		{
			edgeSet.clear();
			
			for (int i = 0; i < 3; i++)
			{
				edgeSet.insert(edge[i]);
			}

			switch (edgeSet.size())
			{
				case 1:
					printf("Equilateral\n");
					break;
				case 2:
					printf("Isosceles\n");
					break;
				default:
					printf("Scalene\n");
			}
		}
		else
		{
			printf("Invalid\n");
		}
	}

	return 0;
}
